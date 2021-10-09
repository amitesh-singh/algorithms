#include "cpu-server.h"

int main()
{
   auto connection = sdbus::createSystemBusConnection("org.cpu.getid");

   cpu cpu(*connection, "/org/cpu/getid");

   //emit the signal "getCalled"
   connection->enterEventLoop();

   return 0;
}

