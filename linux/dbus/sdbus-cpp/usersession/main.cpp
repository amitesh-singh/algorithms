#include <iostream>
#include <vector>
#include <map>
#include <sdbus-c++/sdbus-c++.h>

int main()
{
   const char *serviceName = "com.ami.test2";
   //create Dbus connection to the session bus
   //auto connection = sdbus::createSessionBusConnection(serviceName);
   auto connection = sdbus::createSessionBusConnection();
   connection->requestName(serviceName);

   //creat a proxy which triggers by dbus-send signal emit
   const char *interface = "com.ami.test2";
   const char *objPath = "/com/ami/test2";

   auto obj = sdbus::createObject(*connection, objPath);

   obj->registerMethod("ping").onInterface(interface).implementedAs([]()->std::string {
                                                                    return "pong";
                                                                    });

   obj->finishRegistration();

   std::cout << "Entering into Event loop\n";
   connection->enterEventLoop();

   connection->releaseName(serviceName);

   return 0;
}
