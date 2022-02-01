#include <iostream>
#include <sstream>
#include <stdexcept>

#include <systemd/sd-bus.h>

int _cb(sd_bus_message *message, void *user_data, sd_bus_error *ret_err)
{
    std::cout << "got signal\n";

    int error_code = 0;
    const char *intf_name = sd_bus_message_get_interface(message);

    std::cout << "message interface name: " << intf_name << std::endl;
    std::cout << "member: " << sd_bus_message_get_member(message) << "\n";
    std::cout << "sender: " << sd_bus_message_get_sender(message) << "\n";
 

    sd_bus *bus = (sd_bus *)user_data;

    //parse "sa{sv}as"
    error_code = sd_bus_message_read(message, "s", &intf_name);
    
    if (error_code < 0)
    {
        std::cerr << "some error\n";
        return error_code;
    }
    std::cout << "interface name: " << intf_name << std::endl;

    const char *name, *contents;

    //parse a{sv}
    if (!strcmp(intf_name, "org.sdbuscpp.Add"))
    {
        //this also works, and quite nice and shorter code.
        //pointers: https://systemd-devel.freedesktop.narkive.com/iRfuCIQx/bus-suggestion-for-reading-trough-variants
        //https://www.freedesktop.org/software/systemd/man/sd_bus_message_read.html
        int val = 0;
       
        error_code = sd_bus_message_read(message,  "a{sv}", 1, &name, "b", &val);
        if (error_code < 0)
        {
            std::cerr << "unable to read a{sv}\n";
            return 0;
        }
        std::cout << "val: " << val << std::endl;
     /*
        int val = 0;
        error_code = sd_bus_message_read(message, "b", &val);
        if (error_code < 0)
        {
            std::cerr << "unable to read b\n";
            return 0;
        }
        std::cout << "val: " << val << std::endl;
*/
        /*
        error_code = sd_bus_message_enter_container(message, SD_BUS_TYPE_ARRAY, "{sv}");
        if (error_code < 0)
        {
            return error_code;
        }

        while (sd_bus_message_enter_container(message, SD_BUS_TYPE_DICT_ENTRY, "sv") > 0)
         {
            sd_bus_message_read(message, "s", &name);
            sd_bus_message_peek_type(message, NULL, &contents);

            if ((error_code = sd_bus_message_enter_container(message, SD_BUS_TYPE_VARIANT, contents)) < 0)
            {
                return error_code;
            }

            std::cout << "name: " << name << " contents: " << contents << std::endl;
            if (strcmp(name, "state")) return 0;
            //bool val = true;
            int val; // Do not use C99 'bool' type here, it's typically smaller
          in memory and would cause memory corruption 

            error_code = sd_bus_message_read(message, "b", &val);
            if (error_code < 0)
            {
                std::cerr << "unable to read\n";
            }
            std::cout << "val: " << val << std::endl;

           
            while (sd_bus_message_skip(message, NULL) > 0);

            sd_bus_message_exit_container(message); // Variant ends
            sd_bus_message_exit_container(message); // dict ends
        }
        return sd_bus_message_exit_container(message); /// array ends
    */
    
     
    }
    else
    {
        sd_bus_message_skip(message, "a{sv}");
        return 0;
    }




    return 0;

}

int main(int argc, char **argv)
{
    sd_bus_error sdBusError = SD_BUS_ERROR_NULL;
    sd_bus_message *message = nullptr;

    sd_bus *bus = nullptr;
    sd_event *event = nullptr;

    char *path;
    int error_code = 0;

    try
    {
        error_code = sd_event_default(&event);
        if (error_code < 0)
        {
            throw std::runtime_error("Could not create event loop");
        }
        error_code = sd_bus_default_system(&bus);
        if (error_code < 0)
        {
            std::ostringstream error_msg;
            error_msg << "Failed to connect to system bus, error: "
                      << strerror(-error_code);
            throw std::runtime_error(error_msg.str());
        }
/*
        error_code = sd_bus_call_method(
            bus, "org.freedesktop.systemd1",
            "/org/freedesktop/systemd1",
            "org.freedesktop.systemd1.Manager",
            "StartUnit",
            &sdBusError,
            &message,
            "ss",
            ""
        )
*/
/*
    error_code = sd_bus_match_signal(
        bus,
        nullptr,
        "org.cpu.getid",
        "/org/cpu/getid",
        "org.cpu.getid",
        "getCalled",
        _cb,
        nullptr
    );
  */

    error_code = sd_bus_match_signal(bus, 
                    nullptr,
                    "org.sdbuscpp.add",
                    "/org/sdbuscpp/add",
                    "org.freedesktop.DBus.Properties", "PropertiesChanged",
                    _cb, bus
    );      
    if (error_code < 0) {
        std::ostringstream errorMessage;
        errorMessage << "Failed to match signal, error: "
                    << strerror(-error_code);
        throw std::runtime_error(errorMessage.str());
    }

    error_code = sd_bus_attach_event(bus, event, 0);
    if (error_code < 0)
    {
        std::ostringstream error_msg;
        error_msg << "Could not add sd-bus handling to event bus";
        throw std::runtime_error(error_msg.str());
    }
    std::cout << "running event loop\n";
    error_code = sd_event_loop(event);

    if (error_code < 0)
    {
        throw std::runtime_error("Error while running event loop");
    }

    }
    catch (std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }

    return 0;
}