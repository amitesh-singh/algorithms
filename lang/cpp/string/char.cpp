#include<iostream>
#include <string>

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

   return 0;
}
