#include <iostream>
#include <unordered_set>

int main()
{
   //uses hash, no duplicate elements allowed but sorted
   // but elements are sorted
   std::unordered_set<int> s;
   s.insert(10);
   s.insert(20);
   s.insert(0);

   for (auto &x: s)
     {
        std::cout << x << " ";
     }
   std::cout << std::endl;

   return 0;
}
