
#include "client-intf.h"


class client: public sdbus::ProxyInterfaces<org::cpu::getid_proxy>
{
  public:

   client(std::string dest, std::string objectPath): ProxyInterfaces(std::move(dest), std::move(objectPath))
   {
      registerProxy();
   }

   ~client()
   {
      unregisterProxy();
   }
};
