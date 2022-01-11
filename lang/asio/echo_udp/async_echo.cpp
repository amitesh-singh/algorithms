#include <asio.hpp>
#include <iostream>

std::uint16_t port = 15001;
asio::io_context io;
asio::ip::udp::endpoint receiver(asio::ip::udp::v4(), port);
asio::ip::udp::socket socket_(io, receiver);
char buf[1024];
asio::ip::udp::endpoint sender;

void callback(const std::error_code &, std::size_t bytes_transferred)
{
   std::cout << "message is recieved: message size is : " << bytes_transferred<< std::endl;
   std::cout << sender << std::endl;;
   socket_.send_to(asio::buffer(buf, bytes_transferred), sender);
   socket_.async_receive_from(asio::buffer(buf, 1024), sender, callback);
}

int main()
{
   socket_.async_receive_from(asio::buffer(buf, 1024), sender, callback);

   io.run();

   return 0;
}
