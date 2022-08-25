#ifndef _LOCAL_SEMAPHORE_H
#define _LOCAL_SEMAPHORE_H

#include <thread>
#include <mutex>
#include <condition_variable>

namespace nonstd
{
   template<int MAX_VAL = 32>
       class counting_semaphore
         {
            std::mutex m;
            std::condition_variable cond;
            int val = 0;
           public:
            counting_semaphore(int v = 0): val(v) {
                 if (val > MAX_VAL) val = MAX_VAL;
                 if (val < 0) val = 0;
            }

            void acquire()
              {
                 std::unique_lock<std::mutex> l(m);

                 //both lines work fine. later one is much clearer.
                 //cond.wait(l, [this]()->bool {return val > 0; }); -> while (!lambda()) cond.wait(l);
                 while (!(val > 0))
                   cond.wait(l);

                 val--;
              }

            void release()
              {
                 std::unique_lock<std::mutex> l(m);
                 if (val < MAX_VAL)
                   val++, cond.notify_one();
              }
         };
   using binary_semaphore = counting_semaphore<1>;
}

#endif
