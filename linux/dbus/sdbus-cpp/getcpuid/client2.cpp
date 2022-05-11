#include <iostream>
#include <sdbus-c++/sdbus-c++.h>
#include <string>
#include <tuple>

using namespace std;

   static constexpr const char* SERVICE = "org.cpu.getid";
   static constexpr const char* OBJECT = "/org/cpu/getid";
class myclient:
    public sdbus::ProxyInterfaces<sdbus::Properties_proxy>
{
   static constexpr const char* INTERFACE_NAME = "org.cpu.getid";
  public:
   myclient(std::string service, std::string obj): ProxyInterfaces(service, obj) 
   {
      getProxy().uponSignal("getCalled").onInterface(INTERFACE_NAME).call([this](){ std::cout << "signal is called\n"; });
      registerProxy();

   }
   ~myclient()
     {
        unregisterProxy();
     }
    void onPropertiesChanged(const string &interface,
            const map<string, sdbus::Variant> &changed,
            const vector<string> &invalidated) final
    {
     }
    int32_t id()
     {
         return getProxy().getProperty("id").onInterface(INTERFACE_NAME);
     }
};

int main(int argc, char **argv)
{
   myclient client (SERVICE, OBJECT);

   std::cout << "id: " << client.id() << std::endl;

   return 0;
}
