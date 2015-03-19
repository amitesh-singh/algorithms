#include <iostream>
#include <iterator> //for ostream_iterator
#include <vector>

using namespace std;

int main()
{
   int arr[7] = {1, 2, 4, 43, 324, 23432, 222};
   vector<int> v(7);

   //copy the data from C array to vector using copy
   // src-start, src-end, dst
   copy(arr, arr + 7, v.begin());

   //print the array
   copy(arr, arr + sizeof(arr)/sizeof(arr[0]),
        ostream_iterator<int>(cout, ","));
   cout << endl;
   //print the vector 
   copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
   cout << endl;

   return 0;
}
