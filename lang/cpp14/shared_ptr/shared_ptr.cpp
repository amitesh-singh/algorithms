#include <iostream>
#include <memory> //for shared_ptr

using namespace std;


class Foo
{
 public:
    int a = 0;
    shared_ptr<int> p;
    Foo(): p(make_shared<int>())
   {
      std::cout << "Foo()\n";
   }
};

int main()
{
   Foo f;

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

   Foo *foo = new Foo;
   shared_ptr<Foo> sharedFoo(foo);
   //shared_ptr<Foo> sharedFoo2(foo); //don't do this
   // this will result into double free.
   cout << sharedFoo->a << endl;
   /*
    * Ownership Transfer of shared_ptr

By default, shared_ptr increments the reference count and doesn't transfer the ownership. However, it can be made to transfer the ownership using std::move:

shared_ptr<int> up = make_shared<int>();
// Transferring the ownership
shared_ptr<int> up2 = move(up);
// At this point, the reference count of up = 0 and the
// ownership of the pointer is solely with up2 with reference count = 1

*/
   shared_ptr<Foo> rightFooOwner = std::move(sharedFoo);
   cout << sharedFoo.use_count() << endl;
   cout << rightFooOwner.use_count() << endl;


   return 0;
}
