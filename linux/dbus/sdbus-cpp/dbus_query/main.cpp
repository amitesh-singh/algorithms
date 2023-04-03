#include <iostream>
#include <vector>
#include <map>
#include <sdbus-c++/sdbus-c++.h>

int main()
{
   //const char *serviceName = "com.ami.test";
   //create Dbus connection to the session bus
   //auto connection = sdbus::createSessionBusConnection(serviceName);
   auto connection = sdbus::createSessionBusConnection();

   //creat a proxy which triggers by dbus-send signal emit
   const char *interface = "org.freedesktop.DBus";
   const char *objPath = "/org/freedesktop/DBus";

   auto obj = sdbus::createProxy("org.freedesktop.DBus", objPath);
   obj->uponSignal("NameAcquired").onInterface(interface).call([](std::string  str) {
                                                               std::cout << "added " << str << std::endl;
                                                               });

   obj->uponSignal("NameLost").onInterface(interface).call([](std::string  str) {
                                                               std::cout << "added " << str << std::endl;
                                                               });
   obj->uponSignal("NameOwnerChanged").onInterface(interface).call([](std::string  str) {
                                                               std::cout << "added " << str << std::endl;
                                                               });
   obj->finishRegistration();

   std::cout << "Entering into Event loop\n";
   connection->enterEventLoop();

   return 0;
}