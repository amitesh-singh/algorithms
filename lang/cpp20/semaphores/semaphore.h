#ifndef __semaphore_h__
#define __semaphore_h__

#include <thread>
#include <mutex>
#include <condition_variable>

namespace nonstd
{
   template<int MAX_VAL = 1024>
   class semaphore
     {
        int val = 0;
        std::mutex m;
        std::condition_variable cond;

       public:
        semaphore(int init = 0): val(init) {}

        void acquire()
          {
             std::unique_lock<std::mutex> l(m);
             cond.wait(l, [this]()->bool { return val > 0; });
             --val;
          }

        void release()
          {
             std::unique_lock<std::mutex> l(m);
             if (val < MAX_VAL)
               ++val, cond.notify_one();
          }
     };
}

#endif
