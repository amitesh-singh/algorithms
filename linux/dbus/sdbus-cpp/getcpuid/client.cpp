#include "client.h"
#include <iostream>

int main(int argc, char **argv)
{
   client client("org.cpu.getid", "/org/cpu/getid");


   std::cout << client.id() << std::endl;

   sleep(2);

   return 0;
}
