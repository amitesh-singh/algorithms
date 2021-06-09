#ifndef _THREAD_POOL_H__
#define _THREAD_POOL_H__

#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional>
#include <queue>
#include <iostream>

class threadpool
{
   std::mutex m;
   std::condition_variable cond;
   std::vector<std::thread> thread_list;
   std::queue<std::function<void()>> jobs;
   bool terminate = false;
  public:
   threadpool() {}

   void worker()
     {
        std::cout << "starting thread: " << std::this_thread::get_id() << std::endl;       
        while (1)
          {
             std::function<void()> job;
               {
                  std::unique_lock<std::mutex> l(m);
                  cond.wait(l, [this]()->bool { return !jobs.empty() || terminate; });
                  if (!terminate)
                  {
                    job = jobs.front();
                    jobs.pop();
                  }
                  else break;
               }
            if (!terminate)
                job();
          }
     }
   void start()
     {
        int n = std::thread::hardware_concurrency() - 1;
        for (int i = 0; i < n; ++i)
          {
             thread_list.emplace_back(std::move(std::thread(&threadpool::worker, this)));
          }
     }
   void end()
     {
       terminate = true;
       cond.notify_all();

       //join all threads
       int n = std::thread::hardware_concurrency() - 1;
       for (int i = 0; i < n; ++i)
          {
             thread_list[i].join();
          }

     }

   void addJob(std::function<void()> f)
     {
        std::unique_lock<std::mutex> l(m);
        jobs.push(std::move(f));
     }
};
#endif
