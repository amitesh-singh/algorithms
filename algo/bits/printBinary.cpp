#include <iostream>
#include <string>

std::string printBinary(int n, int bits_count)
{
   std::string str = "";
   //32 bits
   for (int i = bits_count - 1; i >= 0; --i)
     {
       if ((n & (1 << i)) == 0)
         str+= "0";
       else
         str += "1";
     }

   return str;
}
//N - 01011000 
int main()
{
   int n;
   std::cout << "Enter the value: ";
   std::cin >> n;
   std::cout << printBinary(n, 9) << std::endl;

   return 0;
}
