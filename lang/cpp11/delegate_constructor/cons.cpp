#include <iostream>

using namespace std;

//C++11 adds the ability to chain constructors together (called delegating constructors)

class Foo
{
 public:
    Foo()
      {
         cout << __PRETTY_FUNCTION__ << endl;
      }
    Foo(int a): Foo()
   {
      cout << __PRETTY_FUNCTION__ << endl;
   }
};

int main()
{
   Foo f(10);
   Foo f2;

   return 0;
}
