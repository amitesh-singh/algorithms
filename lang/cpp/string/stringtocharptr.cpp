#include <iostream>
#include <cstring>
/*
 *1. Use the contiguous storage of C++11

std::string foo{"text"};
auto p = &*foo.begin();

Pro

    Simple and short
    Fast (only method with no copy involved)

Cons

    Final '\0' is not to be altered / not necessarily part of the non-const memory.

 * */
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
