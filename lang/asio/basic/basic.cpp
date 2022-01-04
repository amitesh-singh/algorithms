#include <asio.hpp>
#include <iostream>

int main()
{
   asio::io_context io;

   io.run();
   //it would return.. since there is nothing  to processs
   std::cout << "Job's done.. exiting..";
   return 0;
}
