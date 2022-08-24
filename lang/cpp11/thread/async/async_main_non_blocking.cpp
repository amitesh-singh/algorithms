#include <thread>
#include <chrono>
#include <future>
#include <iostream>

using namespace std::chrono_literals;
int main()
{
   //std::async() returns std::future<function return type>
   auto f = std::async(std::launch::async, []()->int {
                       std::cout << "async:\n";
                       std::this_thread::sleep_for(10s);
                       return 42;
                       });

   while (1)
     {
        if (f.valid() && f.wait_for(10ms) == std::future_status::ready)
          {
             std::cout << "async output: " << f.get() << '\n';
             break;
          }
        //do something in the loop
        std::cout << "doing something in mainloop\n";
     }
   return 0;
}
