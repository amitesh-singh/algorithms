#include "semaphore2.h"
#include <thread>
#include <functional>
#include <iostream>

//print Fizz and Buzz alternatively
class task {
     int n_ {0};

     nonstd::binary_semaphore fizz_sem {1}, buzz_sem {0};
    public:
        task(int n) : n_(n) {}

     void fizz()
       {
          std::cout << "fizz ";
       }

     void buzz()
       {
          std::cout << "buzz ";
       }
     void printFizz(std::function<void()> func)
       {
          for (int i = 1; i <= n_; ++i)
            {
               fizz_sem.acquire();
               func();
               buzz_sem.release();
            }
       }

     void printBuzz(std::function<void()> func)
       {
          for (int i = 1; i <= n_; ++i)
            {
               buzz_sem.acquire();
               func();
               fizz_sem.release();
            }
       }
};

int main()
{
   task t1(10);
   std::thread th1(&task::printFizz, std::ref(t1), std::bind(&task::fizz, std::ref(t1)));
   std::thread th2(&task::printBuzz, std::ref(t1), std::bind(&task::buzz, std::ref(t1)));

   th1.join();
   th2.join();

   return 0;
}
