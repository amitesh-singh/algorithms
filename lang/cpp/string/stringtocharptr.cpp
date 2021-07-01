#include <iostream>
#include <cstring>

int main()
{
   std::string s = "Hello";

   char *p = &s[0];

   p[0] = 'M';
   while (*p)
     {
        std::cout << *p;
        p++;
     }
   return 0;
}
