#include <asio.hpp>
#include <iostream>

class client
{
   asio::steady_timer &t;
   public:
   ~client() {
      std::cout << __PRETTY_FUNCTION__ << std::endl;}
    client(asio::steady_timer &t1) : t(t1)
   {
      t.async_wait([&](const std::error_code &) {
         assert(this);
         std::cout << "crashing..\n";
         t1.expires_after(std::chrono::seconds(5));
      });
   }
};

int main()
{
   asio::io_context io;
   asio::signal_set signals(io, SIGINT, SIGTERM);
   signals.async_wait([&io](const std::error_code&, int signal)
                      {
                      std::cout<<"signal "<<signal<<"\n";
                      //io.stop();
                      });
   asio::steady_timer t1(io);

   t1.expires_after(std::chrono::seconds(5));

   {
      client c(t1);
   }   
   io.run();

   return 0;
}
