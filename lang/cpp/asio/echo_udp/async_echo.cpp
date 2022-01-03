#include <asio.hpp>
#include <iostream>

int main()
{
   std::uint16_t port = 15002;
   asio::io_context io;
   asio::ip::udp::endpoint receiver(asio::ip::udp::v4(), port);
   asio::ip::udp::socket socket(io, receiver);

   char buf[1024];
   asio::ip::udp::endpoint sender;

   socket.async_receive_from(asio::buffer(buf, 1024), sender,
                             [&](const std::error_code &err, std::size_t bytes_transferred)
                             {
                             std::cout << "message is recieved: message size is : " << bytes_transferred<< std::endl;
                             socket.send_to(asio::buffer(buf, bytes_transferred), sender);
                             });
   std::cout << "Send to\n";

   io.run();
   return 0;
}
