#include <iostream>
#include <vector>
#include <map>
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
   proxy->uponSignal("ext2").onInterface(intfName).call([](const std::string &sig) {
                                                          std::cerr << "Got Signal: " << sig << "\n";
                                                          });
   proxy->uponSignal("ext3").onInterface(intfName).call([](const std::string &sig, int x) {
                                                          std::cerr << "Got Signal: " << sig << " x: " << x  << "\n";
                                                          });
   proxy->uponSignal("ext4").onInterface(intfName).call([](const std::string &sig, int x, std::vector<int> &v) {
                                                          std::cerr << "Got Signal: " << sig << " x: " << x  << "\n";
                                                          for (auto y: v)
                                                            std::cout << y <<" ,";
                                                            std::cout << '\n';
                                                          });
   proxy->uponSignal("ext5").onInterface(intfName).call([](const std::string &sig, int x, std::vector<uint8_t> &v) {
                                                          std::cerr << "Got Signal: " << sig << " x: " << x  << "\n";
                                                          std::cout << "array size: " << v.size() << "\n";
                                                          for (uint8_t y: v)
                                                            std::cout << int(y) <<" ,";
                                                            std::cout << '\n';
                                                          });
   proxy->uponSignal("ext6").onInterface(intfName).call([](const std::string &sig, int x, std::vector<std::string> &v) {
                                                          std::cerr << "Got Signal: " << sig << " x: " << x  << "\n";
                                                          std::cout << "array size: " << v.size() << "\n";
                                                          for (auto &y: v)
                                                            std::cout << y <<" ,";
                                                            std::cout << '\n';
                                                          });
   proxy->uponSignal("ext7").onInterface(intfName).call([](const std::string &sig, int x, std::map<int, std::string> &v) {
                                                          std::cerr << "Got Signal: " << sig << " x: " << x  << "\n";
                                                          std::cout << "array size: " << v.size() << "\n";
                                                          for (auto &y: v)
                                                            std::cout << y.first<<":" << y.second << ",";
                                                            std::cout << '\n';
                                                          });
   proxy->uponSignal("ext8").onInterface(intfName).call([](const std::string &sig, int x, sdbus::ObjectPath &v) {
                                                          std::cerr << "Got Signal: " << sig << " x: " << x  << "\n";
                                                          std::cout << "object path: " << v << std::endl;
                                                          });
   //TODO: obj path by dbus-send?
   proxy->finishRegistration();

   std::cout << "Enterig into Event loop\n";
   connection->enterEventLoop();

   return 0;
}
