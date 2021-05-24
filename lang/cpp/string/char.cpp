#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
   string s;

   //convert an integer from 0 to 9 to char 
   // just add '0'
   s = ('0' + 1);
   // to get integer if its ascii value is in between 0 to 9, then
   // subtract '0' from it.
   // example: char c = '9';
   // int i = c - '0'; ///-> 9

   cout << s << endl; //s would be 1

   s = "";
   //sort the string
   for (int i = 9; i >= 0; --i)
   {
      s += ('0' + i);
   }

   std::cout << s << std::endl;
   std::sort(begin(s), end(s));
   
   std::cout << s << std::endl;

   return 0;
}
