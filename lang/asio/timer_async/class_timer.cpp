#include <asio.hpp>
#include <iostream>
#include <functional>

using namespace std::chrono_literals;

namespace asio_placeholders
{
  auto error = std::placeholders::_1;
}

class timer
{
   asio::io_context &io;
   asio::steady_timer t;

  public:
   timer(asio::io_context &i): io(i), t(io, 1s)
   {
      t.async_wait(std::bind(&timer::print, this));
   }

   void print()
     {
        std::cout << "print ==\n";
        t.expires_after(1s);
        t.async_wait(std::bind(&timer::print, this));
     }
};

int main()
{
   asio::io_context io;

   timer t(io);

   io.post([]() {
           std::cout << "post callback\n";
           });


   io.run();
   return 0;
}
