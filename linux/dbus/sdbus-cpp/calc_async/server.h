#include <sdbus-c++/sdbus-c++.h>
#include "server-intf.h"
#include <thread>
#include <chrono>
#include <string>
//for 1s stuffs
//
using namespace std::literals::chrono_literals;

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

   void add_async(sdbus::Result<int32_t> &&result, int32_t a1, int32_t a2)
     {
        std::thread([this, methodResult = std::move(result), a1, a2] ()
                    {
                        int res = a1 + a2;
                        std::this_thread::sleep_for(1s);
                        methodResult.returnResults(res);
                        this->emitADD(res);
                    }).detach();
     }
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
