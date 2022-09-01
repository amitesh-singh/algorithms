#pragma once
#include <thread>
#include <atomic>

namespace nonstd {


     template<int COUNT_MAX>
         class counting_semaphore {

              std::atomic<int> val_ {0};
             public:

              counting_semaphore(int val = 0): val_(val) {
                   val_ = [](int v)->int { if (v < 0) return 0;
                        else if (v > COUNT_MAX) return COUNT_MAX;
                        return v;
                   }(val_);
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
