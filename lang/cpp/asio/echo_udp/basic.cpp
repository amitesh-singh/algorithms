#include <asio.hpp>
#include <iostream>

int main()
{
   std::uint16_t port = 15001;
   asio::io_context io;
   asio::ip::udp::endpoint receiver(asio::ip::udp::v4(), port);
   asio::ip::udp::socket socket(io, receiver);

   for (;;)
   {
      char buf[1024];
      asio::ip::udp::endpoint sender;

      std::size_t bytes_transferred = socket.receive_from(asio::buffer(buf), sender);
      socket.send_to(asio::buffer(buf, bytes_transferred), sender);
   }

   return 0;
}
