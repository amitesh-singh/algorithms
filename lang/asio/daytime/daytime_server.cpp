#include <ctime>
#include <iostream>
#include <asio.hpp>

using tcp = asio::ip::tcp;
std::string make_daytime_string()
{
   std::time_t now = time(0);
   return ctime(&now);
}

int main(int argc, char **argv)
{
   asio::io_context io;
   tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 13));

   for (;;)
     {
        tcp::socket socket(io);
        acceptor.accept(socket);
        std::string msg = make_daytime_string();
        std::error_code error;
        asio::write(socket, asio::buffer(msg), asio::transfer_all(), error);

     }



   return 0;
}
