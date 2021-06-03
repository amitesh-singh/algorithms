#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
   int arr[] = {1, 0, 1, 0, 0};

   int ones = std::count(std::begin(arr), std::end(arr), 1);

   std::cout << "ones are: " << ones << std::endl;

   std::vector<int> v;
   for (int i = 1; i < 10; ++i)
     if (i % 2 == 0) v.push_back(0);
     else v.push_back(1);

   int zeros = std::count(begin(v), end(v), 0);

   std::cout << "zeros: " << zeros << std::endl;

   return 0;
}
