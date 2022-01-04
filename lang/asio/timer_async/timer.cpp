#include <asio.hpp>
#include <iostream>
#include <functional>

using namespace std::chrono_literals;

namespace asio_placeholders
{
  auto error = std::placeholders::_1;
}

void tick(const std::error_code &e, asio::steady_timer *t)
{
   std::cout << "timer\n";
   t->expires_after(5s);
   t->async_wait(std::bind(tick, asio_placeholders::error, t));
}

int main()
{
   asio::io_context io;

   asio::steady_timer t(io);

   t.async_wait([](const std::error_code &) {
                    std::cout << "timeout 1\n";
                });
   std::cout << "here\n";

   io.post([]() {
           std::cout << "post callback\n";
           });

   asio::steady_timer t2(io);

   t2.expires_after(5s);
   t2.async_wait(std::bind(tick, asio_placeholders::error, &t2));
   //or 
   // t2.async_wait(std::bind(tick, asio_placeholders::error, std::ref(t2)));

   io.run();
   return 0;
}
