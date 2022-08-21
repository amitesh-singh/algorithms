#include <iostream>
#include <chrono>
#include <thread>

//or using namespace std::literals::chrono_literals
using namespace std::chrono_literals;


int main()
{
   std::thread t([]()->void {
                    std::cout << "inside thread\n";
                    std::this_thread::sleep_for(2s);
                 });

   t.join();

   return 0;
}
