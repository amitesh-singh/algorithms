#include <iostream>
#include <set>

int main()
{
   //how to merge two multisets 
   std::multiset<int> m1 = {1, 2, 3};
   std::multiset<int> m2 = {4, 5, 6};

   //this is how you merge a set into another.
   m2.insert(m1.begin(), m1.end());

   for (auto &x: m2)
     std::cout << x << "->";
   std::cout << std::endl;

   return 0;
}
