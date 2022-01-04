#include <iostream>
#include <asio.hpp>
#include <thread>
#include <array>
//./a.out time-a-g.nist.gov
using tcp = asio::ip::tcp;
int main(int argc, char **argv)
{
   asio::io_context io;
   asio::ip::tcp::resolver resolver(io);
   if (argc != 2)
     {
        std::cerr << argv[0] << " <host>" << std::endl;
        exit(-1);
     }
   asio::ip::tcp::resolver::results_type results = resolver.resolve(argv[1], "daytime");
   for (asio::ip::tcp::endpoint const & endpoint : results)
     std::cout << endpoint << std::endl;


   tcp::socket socket(io);
   asio::connect(socket, results);

   std::array<char, 128> buf;
   std::error_code e;

   std::size_t len = socket.read_some(asio::buffer(buf), e);
   if (e == asio::error::eof)
     {
        std::cerr << "connect closed by peer\n";
     }
   std::cout.write(buf.data(), len);

   io.run();

   return 0;
}
