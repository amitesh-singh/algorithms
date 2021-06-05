#include "semaphore.h"
#include <iostream>

nonstd::binary_semaphore t1Tot2(0), t2Tot1(0), mainTot1(0);
void t1_f()
{
   mainTot1.acquire();
   while (1)
     {
        t2Tot1.acquire();
        std::cout << "t1-" << " ";
        t1Tot2.release();
     }
}

void t2_f()
{
   while (1)
     {
        t1Tot2.acquire();
        std::cout << "t2-" << " ";
        t2Tot1.release();
     }
}

int main()
{
   std::thread t1(t1_f);
   std::thread t2(t2_f);
   mainTot1.release();
   t2Tot1.release();

   t1.join();
   t2.join();
   return 0;
}
