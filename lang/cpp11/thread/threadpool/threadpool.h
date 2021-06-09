#ifndef _THREAD_POOL_H__
#define _THREAD_POOL_H__

#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional>
#include <queue>
#include <iostream>

template<int MAX_THREADS = std::thread::hardware_concurrency - 1>
class threadpool
{
   std::mutex m;
   std::condition_variable cond;
   std::vector<std::thread> thread_list;
   std::queue<std::function<void()>> jobs;
   bool terminate = false;
   volatile bool working[MAX_THREADS];
  public:
   threadpool() {
        for(int i = 0; i < MAX_THREADS; ++i)
          working[i] = false;
   }

   void worker(int id)
     {
        std::cout << "starting thread: (" << id << "): " <<  std::this_thread::get_id() << std::endl;
        while (1)
          {
             std::function<void()> job;
               {
                  std::unique_lock<std::mutex> l(m);
                  std::cout << "waiting here: " << id << "working flag: " << working[id]  << std::endl;
                  cond.wait(l, [this, id]()->bool { return (!jobs.empty()) || terminate; });
                  working[id] = true;
                  if (!terminate)
                  {
                    job = jobs.front();
                    jobs.pop();
                  }
                  else break;
               }
             if (!terminate)
               job();
             working[id] = false;
          }
     }
   void start()
     {
        int n = MAX_THREADS;
        std::cout << "available threads are: " << n << std::endl;
        for (int i = 0; i < n; ++i)
          {
             thread_list.emplace_back(std::move(std::thread(&threadpool::worker, this, i)));
          }
     }
   void end()
     {
       m.lock();
       terminate = true;
       m.unlock();
       cond.notify_all();

       //join all threads
       int n = std::thread::hardware_concurrency() - 1;
       for (int i = 0; i < n; ++i)
          {
             thread_list[i].join();
          }

       //clear the thread
       thread_list.clear();

       //delete the jobs if it's there
       while (!jobs.empty())
         jobs.pop();
     }

   void addJob(std::function<void()> f)
     {
        std::unique_lock<std::mutex> l(m);
        jobs.push(std::move(f));
        //we need to notify one of thread to do the job
        cond.notify_one();
     }
};
#endif
