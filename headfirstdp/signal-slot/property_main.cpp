#include "property.h"
#include <iostream>

int main()
{
   property<int> p1(10);

   p1.on_change().connect([](int val)
                          {
                            std::cout << "value is changed to: " << val << std::endl;
                          });
   p1 = 12;
   p1 = 32;
   return 0;
}
