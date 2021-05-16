#include <iostream>
#include <algorithm>
#include <vector>

//with predicate
bool pred(int i, int j)
{
   if (j == i*2)
     {
        return true;
     }
   return false;
}

int main()
{
   std::vector<int> v1 = { 1, 2, 3, 5, 7, -1};
   std::vector<int> v2 = {3, 5, 7};

   //check if v2 is present in v1
   auto it = std::search(begin(v1), end(v1), begin(v2), end(v2));
   if (it != end(v1))
     std::cout << "v2 is present in v1 at pos: " << (it - begin(v1)) << "\n";
   else
     std::cout << "v2 is not present in v1\n";

   v2.push_back(10);

   it = std::search(begin(v1), end(v1), begin(v2), end(v2));
   if (it != end(v1))
     std::cout << "v2 is present in v1\n";
   else
     std::cout << "v2 is not present in v1\n";


   v1.clear();
   v2.clear();

   for(int i = 0; i < 10; ++i)
     {
        v1.push_back(i);
        if (i > 4)
          v2.push_back(i*2);
     }

   std::cout << " v1: ";
   for (auto &&x: v1)
     std::cout << x << ", ";
   std::cout << "\n";
   std::cout << " v2: ";
   for (auto &&x: v2)
     std::cout << x << ", ";
   std::cout << "\n";

   it = std::search(begin(v1), end(v1), begin(v2), end(v2), pred);
   if (it != end(v1))
     std::cout << "v2 is present in v1 at pos: " << (it - begin(v1)) << "\n";
   else
     std::cout << "v2 is not present in v1\n";

   return 0;
}
