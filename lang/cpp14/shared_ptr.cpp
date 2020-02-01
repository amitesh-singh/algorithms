#include <iostream>
#include <memory> //for shared_ptr

using namespace std;

int main()
{
   shared_ptr<int> sp1 (new int());
   *sp1 = 100;

   cout << sp1 << ": " << *sp1 << endl;

   // Error-->shared_ptr<int> sp2 = new int(100);
   // instead use make_shared<int>();
   shared_ptr<int> sp2 = std::make_shared<int>();
   *sp2 = -100;
   cout << sp2 << ": " << *sp2 << endl;

   //resetting
   sp1.reset(); //deletes the ptr if ref count is zero

   cout << "ref count = " << sp1.use_count() << endl;

   //resetting previous value and adding new one
   sp2.reset(new int(32));
   cout << "ref count = " << sp2.use_count() << endl;

   //resetting by nullptr.
   //sp2 = nullptr
   sp2 = nullptr;
   cout << "ref count = " << sp2.use_count() << endl;


   // initializing array - only possible in C++17
   shared_ptr<int[]> arr(new int[10]);

   arr[0] = 10;
   arr.get()[1] = 11;
   cout << arr.get()[0] << endl;
   cout << arr[1] << endl;

   return 0;
}
