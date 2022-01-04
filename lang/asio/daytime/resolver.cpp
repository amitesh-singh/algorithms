#include <iostream>
#include <asio.hpp>
#include <thread>
#include <array>

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


   std::cout << "Async way: \n";
   //async way
   resolver.async_resolve(argv[1], "daytime", [&](std::error_code e, asio::ip::tcp::resolver::results_type results) {
                          if (!e)
                          {
                          for (asio::ip::tcp::endpoint const & endpoint : results)
                          std::cout << endpoint << std::endl;
                          }
                          else
                          {
                          }
                          });

   io.run();

   return 0;
}
