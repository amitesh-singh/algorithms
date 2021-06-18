#include <iostream>
#include <unordered_set>

int main()
{
   //uses hash, no duplicate elements allowed but not sorted
   // but elements are not sorted
   std::unordered_set<int> s;
   s.insert(10);
   s.insert(20);
   s.insert(0);

   for (auto &x: s)
     {
        std::cout << x << " ";
     }
   std::cout << std::endl;

   std::cout << *s.lower_bound(10) << std::endl;
   return 0;
}
