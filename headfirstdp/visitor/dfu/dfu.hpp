#pragma once
#include <iostream>

namespace firmware::dfu
{
    struct coap
    {
        int size1_enable;

        void flash()
        {
            std::cout << "flash\n";
            if (size1_enable == true) {
                std::cout << "SIZE1 added\n";
            } else {
                std::cout << "SIZE1 not added\n";
            }
        }
    };

    struct coap_confirm
    {
        void confirm()
        {
            std::cout << "confirm\n";
            success = true;
        }
        bool success { false };
    };
}