#ifndef _THREAD_POOL_H__
#define _THREAD_POOL_H__

#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional>
#include <queue>

class threadpool
{
   std::mutex m;
   std::condition_variable cond;
   std::vector<std::thread> thread_list;
   std::queue<std::function<void()> jobs;

  public:
   threadpool() {}

   void worker()
     {
        while (1)
          {
             auto job;
               {
                  std::unique_lock<std::mutex> l(m);
                  cond.wait(l, [this]()->bool { return !jobs.empty() || terminate; });
                  job = jobs.top();
                  jobs.pop();
               }
             job();
          }
     }
   void start()
     {
        int n = std::thread::hardware_concurrency - 1;
        for (int i = 0; i < n; ++i)
          {
             thread_list.push_back(std::thread(worker));
          }
     }
   void end()
     {
     }
   void addJob(std::function<void()> f)
     {
        std::unique_lock<std::mutex> l(m);
        jobs.push_back(std::move(f));
     }


};
#endif
