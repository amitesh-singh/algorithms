#include <iostream>
#include <vector>


int main()
{
   std::vector<int> v;

   v.push_back(10);
   v.push_back(20);
   v.push_back(10);
   v.push_back(100);
   v.push_back(101);

   for (int i = 0; i < v.size(); ++i)
     {
        std::cout << "v[" << i << "] = " << v[i] << std::endl;
     }

   return 0;
}
