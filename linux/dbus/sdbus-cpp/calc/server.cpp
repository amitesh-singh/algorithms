#include <sdbus-c++/sdbus-c++.h>
#include "server.h"

int main(int argc, char **argv)
{
   // Create D-Bus connection to the system bus and requests name on it.
    const char* serviceName = "com.amitesh.calculator";
    auto connection = sdbus::createSystemBusConnection(serviceName);

    // Create concatenator D-Bus object.
    const char* objectPath = "/com/amitesh/calculator";
    calculator calc(*connection, objectPath);

    // Run the loop on the connection.
    connection->enterEventLoop();

   return 0;
}
