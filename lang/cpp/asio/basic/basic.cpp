#include <asio.hpp>
#include <iostream>

int main()
{
   asio::io_context io;

   io.run();
   //it would return.. since there is nothing  to process
   return 0;
}
