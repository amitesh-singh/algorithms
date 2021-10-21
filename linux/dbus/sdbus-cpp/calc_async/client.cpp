#include "client.h"
#include <iostream>


int main(int argc, char **argv)
{
   const char *destName = "com.amitesh.calculator";
   const char *objectPath = "/com/amitesh/calculator";

   calc_proxy client(destName, objectPath);
   std::cout << "calling async" << std::endl;
   auto res2 = client.add_async(4, 5);

   auto res = client.add(4, 5);
   std::cout << "result: " << res << std::endl;

   res = client.subtract(1000, 1);
   std::cout << "result: " << res << std::endl;

   sleep(2);

   return 0;
}
