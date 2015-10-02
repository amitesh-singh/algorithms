/*
   By default, C++ will provide a default constructor, copy constructor, copy assignment operator (operator=) and a destructor. If you provide alternate versions of any of these functions for your class, C++ will not provide a default version. However, in C++11, you can now specify that you would like the compiler to provide a default one anyway. This is done by prototyping the function and using the default specifier:

   class Foo
   {
   Foo(int x); // Custom constructor
   Foo() = default; // The compiler will now provide a default constructor for class Foo as well
   };
   The default specifier can only be used with functions that have a default.
 */


#include <iostream>

using namespace std;

class Foo
{
 public:
    Foo(int x) {}; // custom constructor
    Foo() = default; //compiler will provide a default constructor for class Foo as well.
};

int main()
{
   Foo f; // will call compiler's default constructor

   Foo f2(100);

   return 0;
}
