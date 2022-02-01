#include <iostream>
#include <sdbus-c++/sdbus-c++.h>


int main()
{
   //create Dbus connection to the system bus
   const char *serviceName = "org.sdbuscpp.add";
   auto connection = sdbus::createSystemBusConnection(serviceName);

   const char *intfName = "org.sdbuscpp.Add";

   //create dbus object
   const char *objPath = "/org/sdbuscpp/add";
   auto add = sdbus::createObject(*connection, objPath);
   bool state = true;
   add->registerProperty("state").onInterface(intfName).withGetter([&]() {
      std::cout << "returning state: " << state <<  std::endl;
      return state;
   });
   //add->registerMethod("addition").onInterface(intfName).implementedAs(std::move(addition));
   add->registerSignal("addition").onInterface(intfName).withParameters<std::string>();
   add->finishRegistration();

   std::cout << "Enterig into main loop\n";

   add->emitPropertiesChangedSignal("org.sdbuscpp.Add", {"state"});
   connection->enterEventLoop();

   return 0;
}
