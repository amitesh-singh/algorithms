#include <iostream>
#include <string>

int main()
{                  // 01234
   std::string str = "meh! hello world";
   std::string s1 = str.substr(1, 3);
   std::cout << str << ": " << s1 << std::endl;

   //how to get a substr after a character.
   str = "dog:cat";
   int pos = str.find(":");
   s1 = str.substr(pos + 1);
   std::cout << str << ": " << s1 << std::endl;


   //form a string after deleting a char
   int index = pos;
   s1 = str.substr(0, index) + str.substr(index+1);
   std::cout << str << ": " << s1 << std::endl;
   
   return 0;
}
