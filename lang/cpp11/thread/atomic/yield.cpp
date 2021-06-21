#include <iostream>
#include <thread>
#include <atomic>

std::atomic<bool> ready = false;

void countN(int id)
{
   while (!ready)
     std::this_thread::yield(); // sending it to the end of the running queue, of the same scheduling priority.
   for (int i = 0; i < 1000000; ++i) {}
   std::cout << id << "->";
}

int main()
{
   std::thread t[10];
   for (int i = 0; i < 10; ++i)
     t[i] = std::thread(countN, i);

   ready = true;
   for (auto &x: t)
     x.join();

   std::cout << std::endl;
   return 0;
}
