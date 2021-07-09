#include <iostream>


int main()
{
   std::pair<int, char> p;
   //first, second
   p.first = 10;
   p.second = 'a';

   std::cout << p.first << ": " << p.second << std::endl;

   //another way to initialize pair
   p = std::make_pair(22, 'b');

   std::cout << p.first << ": " << p.second << std::endl;

   p = {45, 'p'};
   std::cout << p.first << ": " << p.second << std::endl;

   return 0;
}
