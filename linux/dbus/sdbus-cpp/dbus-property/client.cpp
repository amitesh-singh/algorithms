#include <iostream>
#include <sdbus-c++/sdbus-c++.h>

void onAdd(const std::string &str)
{
   std::cout << "Got signal, onAdd: " << str << std::endl;
}
int main()
{
    const char *serviceName = "org.cpu.getid";
   auto connection = sdbus::createSystemBusConnection(serviceName);
   
   const char *destName = "org.sdbuscpp.add";
   const char *objPath = "/org/sdbuscpp/add";
   auto addProxy = sdbus::createProxy(destName, objPath);

   //this will be called whenever PropertiesChanged signal is emitted
   const char *intfName = "org.freedesktop.DBus.Properties";
   addProxy->uponSignal("PropertiesChanged").onInterface(intfName).call([&](const std::string &interface, const std::map<std::string, sdbus::Variant> &dict) {
                                                                        std::cout << "status: " << interface << std::endl;
                                                                        for (auto prop: dict)
                                                                        {
                                                                           std::cout << prop.first << std::endl;
                                                                        }
                                                          });

   addProxy->finishRegistration();

    std::cout << "Enterig into main loop\n";
    connection->enterEventLoop();

   return 0;
}
