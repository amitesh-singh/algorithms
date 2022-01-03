#include <asio.hpp>
#include <iostream>

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

   t2.expires_after(std::chrono::seconds(5));
   t2.async_wait([](const std::error_code &) {
                    std::cout << "timeout 2\n";
                });

   io.run();
   return 0;
}
