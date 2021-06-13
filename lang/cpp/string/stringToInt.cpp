#include <iostream>
#include <string>

int main()
{
   std::string s("123");
   int num;

   num = std::stoi(s);

   std::cout << num << std::endl;

   return 0;
}
