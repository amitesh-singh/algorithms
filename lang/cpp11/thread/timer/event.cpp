#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <functional>
#include <queue>


using namespace std::chrono_literals;

enum class event_type
{
   TIME_OUT //for timeouts
            // MOUSE, KEY etc
};

class timer;
class event_handler
{
  public:
      virtual void handle_event(timer &) = 0;
};
class event
{
  protected:
   event_type et_;
  public:
   virtual void dispatch(event_handler &) = 0;
};

class loop: public event_handler
{
   std::queue<event *> events_;
  public:
      void handle_event(timer &t)
        {
           events_.push((event *)(&t));
        }
      void run()
        {
           while (true)
             {
                std::this_thread::yield();
                if (!events_.empty()) {
                     events_.pop();
                }
             }
        }
};
class timer : public event
{
   std::atomic<bool> active_ {false};
   event_handler &handler_;
  public:
   timer(event_handler &handler): handler_(handler) {
        et_ = event_type::TIME_OUT;
   }
   void dispatch(event_handler &handler) override
     {
        handler.handle_event(*this);
     }

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
                          dispatch(handler_);
                          active_ = false;
                          });
            t.join();
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
                      dispatch(handler_);
                      active_ = false;
                      });
        t.detach();
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
   loop loop;
   timer t1(loop);
     {
   std::function<void()> f = []()->void {std::cout << "meh\n"; };
   t1.wait(std::move(f), 3);
     }
   std::function<void()> f = []()->void { std::cout << "async wait\n"; };
   t1.async_wait(std::move(f), 10);

       loop.run();
   return 0;
}
