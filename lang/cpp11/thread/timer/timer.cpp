#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <unistd.h>

class timer {
     std::atomic<bool> active {false};

    public:
     void setTimeout(auto function, int delay)
       {
          active = true;
          std::thread t ([=]() {
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
          std::thread t ([=]() {
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
};

int main()
{
   timer t;
   t.setTimeout([]()->void { std::cout << "after 3s\n"; }, 3000);

   sleep(10);

   return 0;
}
