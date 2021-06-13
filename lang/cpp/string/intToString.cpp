#include <iostream>
#include <string>

//use std::to_string() to convert ints into std::string defined in <string>
// use std::itoa() to convert char [] into ints.
int main()
{
   int i = 10;

   std::string s  = std::to_string(i);

   std::cout << s << std::endl;


   return 0;
}
