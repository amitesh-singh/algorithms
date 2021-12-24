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

   const char *intfName = "org.sdbuscpp.add";
   add->registerSignal("addition").onInterface(intfName).withParameters<std::string>();
   add->finishRegistration();


   //creat a proxy which triggers by dbus-send signal emit
   const char *destName = "org.sdbuscpp.ext";
   const char *objPath2 = "/org/sdbuscpp/ext";
   auto addProxy = sdbus::createProxy(*connection, destName, objPath2);

   const char *intfName2 = "org.sdbuscpp.ext";

   addProxy->uponSignal("ext").onInterface(intfName2).call([]() {
                                                          std::cerr << "Got Signal\n";
                                                          });
   addProxy->finishRegistration();

   std::cout << "Enterig into main loop\n";
   connection->enterEventLoop();

   return 0;
}
