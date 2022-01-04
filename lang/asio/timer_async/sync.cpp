#include <asio.hpp>
#include <iostream>
#include <functional>
#include <thread>

using namespace std::chrono_literals;

namespace asio_placeholders
{
  auto error = std::placeholders::_1;
}

class timer
{
   asio::io_context &io;
   asio::steady_timer t;
   //this is for sync across threads
   asio::io_context::strand st;

  public:
   timer(asio::io_context &i): io(i), t(io, 1s), st(io)
   {
      t.async_wait(asio::bind_executor(st, std::bind(&timer::print, this)));
   }

   void print()
     {
        std::thread::id this_id = std::this_thread::get_id();
        std::cout << "print ==\n";
        std::cout << this_id << std::endl;
        t.expires_after(1s);
        t.async_wait(asio::bind_executor(st, std::bind(&timer::print, this)));
     }
};

int main()
{
   asio::io_context io;

   timer t(io);

   std::thread th([&]() {
                  io.run();
                  });

   io.post([]() {
           std::cout << "post callback\n";
           });


   io.run();
   return 0;
}
