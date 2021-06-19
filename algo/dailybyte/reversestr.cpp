/*
 * This question is asked by Google. Given a string, reverse all of its characters and return the resulting string.

Ex: Given the following strings...

“Cat”, return “taC”
“The Daily Byte”, return "etyB yliaD ehT”
“civic”, return “civic”
*/

#include <iostream>
#include <string>

std::string reversestr(std::string str)
{
   if (str.size() == 1 || str.size() == 0) return str;

   unsigned int low = 0;
   unsigned int high = str.size() - 1;

   while (low < high)
     {
        std::swap(str[low++], str[high--]);
     }

   return str;
}

int main()
{
   std::cout << reversestr("Cat") << std::endl;
   std::cout << reversestr("The Daily Byte") << std::endl;
   return 0;
}
