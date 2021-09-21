#include <sdbus-c++/sdbus-c++.h>
#include "server.h"

int main(int argc, char **argv)
{
   // Create D-Bus connection to the system bus and requests name on it.
    const char* serviceName = "org.sdbuscpp.concatenator";
    auto connection = sdbus::createSystemBusConnection(serviceName);

    // Create concatenator D-Bus object.
    const char* objectPath = "/org/sdbuscpp/concatenator";
    Concatenator concatenator(*connection, objectPath);

    // Run the loop on the connection.
    connection->enterEventLoop();

   return 0;
}
