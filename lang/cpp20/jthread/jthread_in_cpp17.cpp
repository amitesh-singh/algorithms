#include <thread>
#include <chrono>
#include <atomic>
#include <iostream>

int main()
{
   std::atomic_bool val = true;
   std::thread t([](std::atomic_bool &cont) {
                    while (cont)
                    {
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "working...\n";
                    }
                 }, std::ref(val));

   std::this_thread::sleep_for(std::chrono::seconds(3));
   val = false;
   t.join();

   return 0;
}
