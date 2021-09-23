#include "client.h"
#include <iostream>

bool recvSignal = false;

class client: public sdbus::ProxyInterfaces<org::sdbuscpp::Concatenator_proxy>
{
public:
    client(std::string destination, std::string objectPath):
        ProxyInterfaces(std::move(destination), std::move(objectPath))
   {
      registerProxy();
   }

  ~client()
    {
       unregisterProxy();
    }

  protected:
  void onConcatenated(const std::string &str) override
    {
       std::cout << "Recieved signal with concatenated string " << str << std::endl;
       recvSignal = true;
    }
};


int main(int argc, char **argv)
{
   const char *destName = "org.sdbuscpp.concatenator";
   const char *objectPath = "/org/sdbuscpp/concatenator";

   client client(destName, objectPath);

   std::vector<int> numbers = {1, 2, 3};
   std::string sep = ":";

   auto res = client.concatenate(numbers, sep);
   std::cout << "result: " << res << std::endl;

   //wait until we get the signals
   while (!recvSignal) { sleep(2); }

   return 0;
}
