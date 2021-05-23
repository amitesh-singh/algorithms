#include <unordered_map>
#include <iostream>
#include <list>
struct data
{
   int a, b;
   data(int x, int y): a(x), b(y) {}
};

int main()
{
   std::unordered_map<int, std::list<data> > m2;

   std::list<data> d = m2[1];

   for (auto &x : d)
     std::cout << x.a;

   m2[1].push_back({10, 20});
   for (auto &x : m2[1])
     std::cout << x.a;

   return 0;
}
