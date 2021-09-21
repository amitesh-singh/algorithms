#include <sdbus-c++/sdbus-c++.h>
#include "server-intf.h"

class Concatenator: public sdbus::AdaptorInterfaces<org::sdbuscpp::Concatenator_adaptor>
{
  public:
      Concatenator(sdbus::IConnection& connection, std::string objectPath)
        : AdaptorInterfaces(connection, std::move(objectPath))
    {
        registerAdaptor();
    }

    ~Concatenator()
    {
        unregisterAdaptor();
    }

protected:
    std::string concatenate(const std::vector<int32_t>& numbers, const std::string& separator) override
    {
        // Return error if there are no numbers in the collection
        if (numbers.empty())
            throw sdbus::Error("org.sdbuscpp.Concatenator.Error", "No numbers provided");

        // Concatenate the numbers
        std::string result;
        for (auto number : numbers)
        {
            result += (result.empty() ? std::string() : separator) + std::to_string(number);
        }

        // Emit the 'concatenated' signal with the resulting string
        emitConcatenated(result);

        // Return the resulting string
        return result;
    }
};
