#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <unistd.h>

using namespace std::chrono_literals;

class timer {
     std::atomic<bool> active {false};

    public:
     void setTimeout(auto function, int delay)
       {
          active = true;
          std::thread t ([this, function, delay]() {
                         if (!active.load()) return;
                         std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                         if (!active.load()) return;
                         function();
                         });
          t.detach();
       }

     void setInterval(auto function, int interval)
       {
          active = true;
          std::thread t ([this, function, interval]() {
                         while (active.load()) {
                         std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                         if (!active.load()) return;
                         function();
                         }
                         });
          t.detach();
       }

     void  stop()
       {
          active = false;
       }

     ~timer() {
          stop();
     }
};

int main()
{
   timer t;
   t.setTimeout([]()->void { std::cout << "after 3s\n"; }, 3000);

   std::this_thread::sleep_for(10s);
   return 0;
}
