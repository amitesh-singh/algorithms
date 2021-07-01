#include <iostream>
#include <string>

int main()
{
   std::string s("123");
   int num;

   num = std::stoi(s);

   std::cout << num << std::endl;

   s = "01";
   std::cout << std::stoi(s) << std::endl;

   s = "-134";
   std::cout << std::stoi(s) << std::endl;

   return 0;
}
