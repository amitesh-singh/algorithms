#include <thread>
#include <iostream>
#include <chrono>
#include <atomic>

using namespace std::string_literals;


int main()
{
   //joins automatically
   std::jthread nonInterruptible {[]()->void {
        int counter {0};
        while (counter < 10)
          {
             std::this_thread::sleep_for(std::chrono::milliseconds(200));
             std::cerr << "nonInterruptible" << counter << "\n";
             ++counter;
          }
   }};

   std::jthread interruptible {[](std::stop_token stoken)->void {
        int counter {0};
        while (counter < 10)
          {
             //std::this_thread::sleep_for(0.2s);
             std::this_thread::sleep_for(std::chrono::milliseconds(200));

             if (stoken.stop_requested()) return;
             std::cerr << "interruptible: " << counter << "\n";
             ++counter;
          }

   }};

   //std::this_thread::sleep_for(1s);

   std::this_thread::sleep_for(std::chrono::seconds(1));

   nonInterruptible.request_stop();
   interruptible.request_stop();

   return 0;
}
