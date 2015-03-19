#include <iostream>
#include <algorithm>

using namespace std;

static void
printArr(int arr[], int len)
{
   for (int i = 0; i < len; ++i)
     {
        cout << arr[i] << " ";
     }
   cout << endl;
}

#include <vector>
int main()
{
   //sorting arrays 
   int arr[10] = { 9, 4, 34, 4200, 100, 324,
        87, 98, 87, 422};

   printArr(arr, 10);

   cout << "Sorting arry via std::sort() ---->\n";
   std::sort(arr, arr + sizeof(arr)/sizeof(arr[0]));

   printArr(arr, 10);

   //sorting vector
   std::vector<int> v;

   for (int i = 9; i >= 0; --i)
     {
        v.push_back(rand() % 2398);
     }

   for (int i = 0; i < v.size(); ++i)
     {
        cout << v[i] << " ";
     }
   cout << endl;

   std::sort(v.begin(), v.end());
   for (int i = 0; i < v.size(); ++i)
     {
        cout << v[i] << " ";
     }
   v.clear();

   for (int i = 9; i >= 0; --i)
     {
     }

   return 0;
}
