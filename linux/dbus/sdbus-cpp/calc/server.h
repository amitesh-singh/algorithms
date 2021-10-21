#include <sdbus-c++/sdbus-c++.h>
#include "server-intf.h"

class calculator: public sdbus::AdaptorInterfaces<com::amitesh::calculator_adaptor>
{
  public:
      calculator(sdbus::IConnection& connection, std::string objectPath)
          : AdaptorInterfaces(connection, std::move(objectPath))
        {
           registerAdaptor();
        }
      ~calculator()
        {
           unregisterAdaptor();
        }

  private:
   int32_t add(const int32_t& a1, const int32_t& a2) override
   {
        int res = a1 + a2;
        emitADD(res);
        return res;
   }

   int32_t subtract(const int32_t& a1, const int32_t& a2) override
   {
        int res = a1 - a2;
        emitSUBTRACT(res);
        return res;
   }
};
