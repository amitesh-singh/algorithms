#include <asio.hpp>
#include <iostream>

int main()
{
   asio::io_context io;
   asio::signal_set signals(io, SIGINT, SIGTERM);
   signals.async_wait([&io](const std::error_code&, int signal)
                      {
                      std::cout<<"signal "<<signal<<"\n";
                      //io.stop();
                      });
   io.run();

   return 0;
}
