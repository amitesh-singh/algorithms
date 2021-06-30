#include <iostream>

//std::isdigit(char c) can be used

bool isNumber(const std::string &str)
{
   for (auto &x: str)
     {
        if (std::isdigit(x) == false) return false;
     }

   return true;
}

int main()
{
   std::cout << "123: " << isNumber("123") << std::endl;
   std::cout << "45e: " << isNumber("45e") << std::endl;

   return 0;
}
