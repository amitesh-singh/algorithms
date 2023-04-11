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
   obj->uponSignal("NameAcquired").onInterface(interface).call([](const std::string &str) {
                                                               std::cout << "NameAcquired " << std::endl;
                                                               });

   obj->uponSignal("NameLost").onInterface(interface).call([](const std::string  &str) {
                                                               std::cout << "NameLost " << str << std::endl;
                                                               });
   obj->uponSignal("NameOwnerChanged").onInterface(interface).call([](const std::string  &name, const std::string &from, const std::string &to) {
                                                               std::cout << "NameOwnerChanged: name: " << name << " from:" << from << " to:" << to << std::endl;
                                                               });
   obj->finishRegistration();

   std::cout << "Entering into Event loop\n";
   if (obj->propertyExists("org.freedesktop.DBus", "NameOwnerChanged")) {
        std::cout << "property exists\n";
   } else {
        std::cout << "property does not exist ---->>>> \n" << std::endl;
   }
   connection->enterEventLoop();

   return 0;
}
