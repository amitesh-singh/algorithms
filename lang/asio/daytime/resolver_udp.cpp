#include <asio.hpp>
#include <iostream>

using udp = asio::ip::udp;
int main(int argc, char **argv)
{
   if (argc != 2)
     {
        std::cerr << argv[0] << " <host> " << std::endl;
        return -1;
     }

   asio::io_context io;
   std::string server(argv[1]), port("15001");

   udp::resolver resolver(io);
   udp::resolver::query query(udp::v4(), server, port);
   udp::endpoint remote_endpoint(*resolver.resolve(query));

   std::cout << remote_endpoint << std::endl;

   io.run();
   return 0;;
}
