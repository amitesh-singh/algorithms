#include <iostream>
#include <sdbus-c++/sdbus-c++.h>


int main()
{
   //create Dbus connection to the system bus
   const char *serviceName = "org.sdbuscpp.add";
   auto connection = sdbus::createSystemBusConnection(serviceName);


   //create dbus object
   const char *objPath = "/org/sdbuscpp/add";
   auto add = sdbus::createObject(*connection, objPath);

   auto addition = [&add](const std::vector<int> numbers, const std::string &
                          separator)
     {
        std::string result;
        for (auto number: numbers)
          result += (result.empty() ? std::string() : separator) + std::to_string(number);

        const char *intfName = "org.sdbuscpp.Add";
        add->emitSignal("addition").onInterface(intfName).withArguments(result);

        return result;
     };

   //register dbus methods and signals on the add object and exports the object.

   const char *intfName = "org.sdbuscpp.Add";
   add->registerMethod("addition").onInterface(intfName).implementedAs(std::move(addition));
  add->registerSignal("addition").onInterface(intfName).withParameters<std::string>();
  add->finishRegistration();

  std::cout << "Enterig into main loop\n";
  connection->enterEventLoop();

   return 0;
}
