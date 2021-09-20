#include <iostream>
#include <sdbus-c++/sdbus-c++.h>

void onAdd(const std::string &str)
{
   std::cout << "onAdd: " << str << std::endl;
}
int main()
{
   const char *destName = "org.sdbuscpp.add";
   const char *objPath = "/org/sdbuscpp/add";
   auto addProxy = sdbus::createProxy(destName, objPath);

   const char *intfName = "org.sdbuscpp.Add";

   addProxy->uponSignal("addition").onInterface(intfName).call([](const std::string &str) {
                                                          onAdd(str);
                                                          });

   addProxy->finishRegistration();

   std::vector<int> numbers = {1, 2, 3};

   std::string sep = ":";

     {

        std::string str;

        addProxy->callMethod("addition").onInterface(intfName).withArguments(numbers, sep).storeResultsTo(str);
        std::cout << str << std::endl;
     }

   return 0;
}
