#include <iostream>
#include <algorithm>
#include <vector>


// Usage of sort() with vector<int>
using namespace std;

int main()
{
   vector<int> v;

   v.push_back(10);
   v.push_back(1);
   v.push_back(2);
   v.push_back(100);
   v.push_back(78);

   for (int i = 0; i < v.size(); ++i)
     {
        cout << v[i] << ",";
     }
   cout << endl;
   //After sorting
   std::sort(v.begin(), v.end());
   cout << "sorted Array: ";
   for (int i = 0; i < v.size(); ++i)
     {
        cout << v[i] << ",";
     }
   cout << endl;


   return 0;
}
