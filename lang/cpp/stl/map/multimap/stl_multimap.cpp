#include <iostream>
#include <map>
using namespace std;

int main()
{
   std::multimap<int, int> m;

   m.insert(std::pair<int, int>(1, 20));
   m.insert(std::pair<int, int>(1, 23));
   m.insert(std::pair<int, int>(1, 23));
   m.insert(std::pair<int, int>(2, 23));
   m.insert(std::pair<int, int>(3, 23));

   for (auto &x: m)
     {
        for (auto &y: x.second)
          std::cout << x.first << ":" << y << std::endl;
     }

   return 0;
}
