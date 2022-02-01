#include <iostream>
#include <sstream>
#include <stdexcept>

#include <systemd/sd-bus.h>

int main(int argc, char **argv)
{
    sd_bus_error sdBusError = SD_BUS_ERROR_NULL;
    sd_bus_message *message = nullptr;

    sd_bus *bus = nullptr;
    char *path;
    int error_code = 0;

    try
    {
        error_code = sd_bus_default_system(&bus);
        if (error_code < 0)
        {
            std::ostringstream error_msg;
            error_msg << "Failed to connect to system bus, error: "
                      << strerror(-error_code);
            throw std::runtime_error(error_msg.str());
        }

        
    }
    catch (std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }

    return 0;
}