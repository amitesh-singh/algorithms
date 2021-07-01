//TODO
// 0 to 9 and a - f and A - F
//

#include <iostream>

bool isHex(const std::string &str)
{
   for (auto &x: str)
     {
        if ( (x < '0' or x > '9') and (x < 'a' or x > 'f') and (x < 'A' or x > 'F'))
          return false;
     }

   return true;
}

int main()
{
   std::cout << isHex("AFCD") << std::endl;
   std::cout << isHex("BGtg") << std::endl;
   return 0;
}
