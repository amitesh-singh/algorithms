#pragma once
#include <thread>
#include <atomic>

namespace nonstd {


     template<int COUNT_MAX>
         class counting_semaphore {

              std::atomic<int> val_ {0};
             public:

              counting_semaphore(int val = 0): val_(val) {
                   if (val_ < 0) val_ = 0;
                   else if (val_ > COUNT_MAX) val_ = COUNT_MAX;
              }
                 void acquire()
                   {
                      while (val_ == 0) std::this_thread::yield();
                      --val_;
                   }

                 void release()
                   {
                      if (val_ < COUNT_MAX)
                        ++val_;
                   }
         };

     using binary_semaphore = counting_semaphore<1>;
}
