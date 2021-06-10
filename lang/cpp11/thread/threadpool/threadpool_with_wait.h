#ifndef _THREAD_POOL_H__
#define _THREAD_POOL_H__

#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional>
#include <queue>
#include <iostream>

template<typename T>
class myfuture
{
  public:
  std::mutex m;
  std::condition_variable cond;
  void get()
  {
    //blocking call
    std::unique_lock<std::mutex> l(m);
    cond.wait(l);
  }
};

template<int MAX_THREADS = std::thread::hardware_concurrency() - 1>
class threadpool
{
   struct job_info
   {
     std::function<void()> f;
     myfuture<void> *fobject;
     job_info(std::function<void()> &_f, myfuture<void> *_fobject): f(_f), fobject(_fobject)
     {

     }
   };

   std::mutex m;
   std::condition_variable cond;
   std::vector<std::thread *> thread_list;
   std::queue<job_info *> jobs;
   bool terminate = false;
  public:
   threadpool() {}

   void worker()
     {
        std::cout << "starting thread: " << std::this_thread::get_id() << std::endl;       
        while (1)
          {
             job_info *job;
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
            {
                job->fobject->m.lock();
                job->f();
                job->fobject->m.unlock();
                job->fobject->cond.notify_one();
                delete job;
            }

          }
     }
   void start()
     {
        int n = MAX_THREADS;
        std::cout << "available threads are: " << n << std::endl;
        for (int i = 0; i < n; ++i)
          {
             thread_list.push_back(new std::thread(&threadpool::worker, this));
          }
     }

   void end()
     {
       m.lock();
       terminate = true;
       m.unlock();
       cond.notify_all();

       //join all threads
       int n = MAX_THREADS;
       for (int i = 0; i < n; ++i)
          {
             thread_list[i]->join();
          }


       for (auto &x: thread_list)
         {
            delete x;
         }
       while (!jobs.empty())
         {
            auto job = jobs.front();
            jobs.pop();
            delete job;
         }
     }

   void addJob(std::function<void()> f, myfuture<void> &fobject)
     {
        std::unique_lock<std::mutex> l(m);
        jobs.push(new job_info(f, &fobject));
        cond.notify_one();
     }
};
#endif
