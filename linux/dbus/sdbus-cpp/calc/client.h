#include "client-intf.h"
#include <iostream>

class calc_proxy : public sdbus::ProxyInterfaces<com::amitesh::calculator_proxy>
{
  public:
      calc_proxy(std::string destination, std::string objectPath): ProxyInterfaces(std::move(destination), std::move(objectPath))
   {
      registerProxy();
   }
  ~calc_proxy()
    {
       unregisterProxy();
    }

  protected:
  void onADD(const int32_t& result) override
    {
       std::cout << "Add signal\n";
    }
  void onSUBTRACT(const int32_t& result) override
    {
       std::cout << "Subtract Signal\n";
    }
};
