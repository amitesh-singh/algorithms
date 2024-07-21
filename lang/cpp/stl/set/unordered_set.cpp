#include <iostream>
#include <unordered_set>

void unordered_set_insert(auto &s, auto&&... elements)
{
   (s.insert(elements), ...);
}

int main()
{
   //uses hash, no duplicate elements allowed but not sorted
   // but elements are not sorted
   std::unordered_set<int> s;

   auto unordered_set_insert_lambda = [](auto &s, auto&&... elements) {
      (s.insert(elements), ...);
   };

   s.insert(10);
   s.insert(20);
   s.insert(0);
   unordered_set_insert(s, 11, 21, 1);
   unordered_set_insert_lambda(s, 12, 22, 2);
   
   for (auto &x: s)
     {
        std::cout << x << " ";
     }
   std::cout << std::endl;

   auto itr = s.find(10);
   if (itr != s.end()) {
      std::cout << *itr << " is found" << std::endl;
   }

   return 0;
}
