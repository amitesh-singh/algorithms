#include <iostream>

//from 0  to 1, e,g, print decimal of 0.72
// also if it can't be printed show error..
std::string printDecimal(double num)
{
   std::string str(".");

   if (num >= 1 || num <= 0)
     return "ERROR";

   while (num > 0)
     {
        if (str.size() >= 64) return "-ERROR";
        double r = 2 * num;
        if (r >= 1)
          {
             str += "1";
             num = r - 1;
          }
        else
          {
             str += "0";
             num = r;
          }
     }

   return str;
}

int main()
{
   double num;
   std::cout << "Enter decimal number: (0 - 1): ";
   std::cin >> num;
   std::string str = printDecimal(num);
   std::cout << str << std::endl;
   std::cout << "len: " << str.size() << std::endl;
   return 0;
}
