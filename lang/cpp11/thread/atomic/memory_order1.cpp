#include <iostream>
#include <thread>
#include <atomic>

std::atomic<bool> x, y ;

int main()
{
   std::thread t1([]()->void {
                  x.store(true, std::memory_order_relaxed);
                  y.store(true, std::memory_order_relaxed);
                  });

   std::thread t2([]()->void {
                  while (!y.load(std::memory_order_relaxed));
                  if (x.load(std::memory_order_relaxed))
                    std::cout << "x is true and y also\n";

                  });

   t1.join();
   t2.join();

   return 0;
}
