#include <memory>
#include <algorithm>
#include <vector>
#include <iostream>


int main()
{
   std::vector<int> v(10);

   std::fill(std::begin(v), std::begin(v) + 4, 0);
   std::fill(std::begin(v) + 5, std::end(v), 1);

   for (const auto &x: v)
     std::cout << x << " ";

   std::cout << '\n';

   return 0;
}
