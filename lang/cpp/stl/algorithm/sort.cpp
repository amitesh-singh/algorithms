#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator> //for ostream_iterator

using namespace std;

int main()
{
   //sorting arrays 
   int arr[10] = { 9, 4, 34, 4200, 100, 324, 87, 98, 87, 422};

   std::copy(arr, arr + sizeof(arr)/sizeof *arr, std::ostream_iterator<int>(std::cout, ", "));
   std::cout << std::endl;

   cout << "Sorting arry via std::sort() ---->\n";
   std::sort(arr, arr + sizeof(arr)/sizeof(arr[0]));

   std::copy(arr, arr + sizeof(arr)/sizeof *arr, std::ostream_iterator<int>(std::cout, ", "));
   std::cout << std::endl;


   //sorting vector
   std::vector<int> v;

   srand(time(nullptr));

   for (int i = 9; i >= 0; --i)
     {
        v.push_back(rand() % 2398);
     }

   std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
   std::cout << std::endl;

   std::sort(v.begin(), v.end());

   std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
   std::cout << std::endl;

   v.clear();
   return 0;
}
