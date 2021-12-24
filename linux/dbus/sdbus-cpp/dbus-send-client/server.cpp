#include <iostream>
#include <sdbus-c++/sdbus-c++.h>

int main()
{
   //create Dbus connection to the system bus
   const char *serviceName = "org.sdbuscpp.add";
   auto connection = sdbus::createSystemBusConnection(serviceName);

   //creat a proxy which triggers by dbus-send signal emit
   const char *destName = "org.sdbuscpp.ext";
   const char *objPath = "/org/sdbuscpp/ext";
   auto proxy = sdbus::createProxy(*connection, destName, objPath);

   const char *intfName = "org.sdbuscpp.ext";
   proxy->uponSignal("ext").onInterface(intfName).call([]() {
                                                          std::cerr << "Got Signal\n";
                                                          });
   proxy->finishRegistration();

   std::cout << "Enterig into Event loop\n";
   connection->enterEventLoop();

   return 0;
}
