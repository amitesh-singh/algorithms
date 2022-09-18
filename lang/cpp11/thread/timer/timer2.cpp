#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <functional>


using namespace std::chrono_literals;

class timer
{
   std::atomic<bool> active_ {false};
  public:

   template<typename... Args>
       void wait(std::function<void(Args...)> &&func, size_t delay)
         {
            if (active_)
              {
                 return;
              }
            active_ = true;

            std::thread t([this, func = std::move(func), delay]()->void {
                          size_t count_1s = 0;
                          while (active_ and count_1s < delay)
                          {
                          std::this_thread::sleep_for(1s);
                          ++count_1s;
                          }
                          func();
                          });
            t.join();
            active_ = false;
         }

   template<typename... Args>
   void async_wait(std::function<void(Args...)> &&func, size_t delay)
     {
        if (active_)
          {
             return;
          }
        active_ = true;

        std::thread t([this, func = std::move(func), delay]()->void {
                      size_t count_1s = 0;
                      while (active_ and count_1s < delay)
                      {
                      std::this_thread::sleep_for(1s);
                      ++count_1s;
                      }
                      func();
                      });
        t.detach();
        active_ = false;
     }

   void cancel()
     {
        active_ = false;
     }
   bool is_active() const
     {
        return active_;
     }

};

int main()
{
   timer t1;
   std::function<void()> f = []()->void {std::cout << "meh\n"; };
   t1.wait(std::move(f), 3);
   return 0;
}
