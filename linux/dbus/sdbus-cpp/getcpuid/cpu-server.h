#include "server-intf.h"

class cpu : public sdbus::AdaptorInterfaces<org::cpu::getid_adaptor>
{
  public:
      cpu(sdbus::IConnection &connection, std::string objectPath)
          : AdaptorInterfaces(connection, std::move(objectPath))
        {
           registerAdaptor();
        }

      ~cpu()
        {
           unregisterAdaptor();
        }

      int32_t id() override
        {
           emitGetCalled();
           return 7;
        }
};
