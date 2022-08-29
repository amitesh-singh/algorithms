#pragma once 

#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <queue>
#include <vector>
#include <iostream>

namespace nonstd {
     class threadpool {

          std::mutex m_;
          std::condition_variable cv_;
          std::queue<std::packaged_task<void()>> tasks_;
          std::vector<std::thread> threads_;
          int threads_count_ { 1 };

         public:

          threadpool(int N = 1) : threads_count_(N) {
               if (N <= 0) threads_count_ = 1;
               int hw_count = std::thread::hardware_concurrency();
               if (N > hw_count) threads_count_ = hw_count;
          }

          void start() {
               for (int id = 1; id <=  threads_count_; ++id) {
                    threads_.emplace_back(std::thread(&threadpool::worker, this, id));
               }
          }

          void worker(int id) {
            while (true)
            {
               std::packaged_task<void()> f;
                 {
                    std::unique_lock<std::mutex> l(m_);
                    while (tasks_.empty())
                      cv_.wait(l);

                    f = std::move(tasks_.front());
                    tasks_.pop();
                 }
               if (!f.valid()) return;
               f();
            }
          }

          void stop() {
                 {
                    std::unique_lock<std::mutex> l(m_);
                    for (int i = 0; i < threads_count_; ++i) {
                         tasks_.push({});
                    }
                 }
               cv_.notify_all();
               for (auto &t :  threads_) {
                    t.join();
               }
          }

          ~threadpool() {
               stop();
          }

          /*
          template<typename F, typename return_type = std::result_of_t<F &()>>
              std::future<return_type> addJob(F &&f) {
                   std::packaged_task<return_type()> pt(std::forward<F>(f));
                   std::future<return_type> ret = pt.get_future();
                     {
                        std::unique_lock<std::mutex> l(m_);
                        tasks_.push(std::move(pt));
                     }
                   cv_.notify_one();

                   return ret;
              }
              */

          template<typename F>
          std::future<void> addJob(F &&f) {
               std::packaged_task<void()> task(std::forward<F>(f));
               auto ret = task.get_future();
                 {
                    std::unique_lock<std::mutex> l(m_);
                    tasks_.push(std::move(task));
                 }
               cv_.notify_one();

               return ret;
          }
     };
}
