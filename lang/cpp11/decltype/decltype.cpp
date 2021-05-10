#include <iostream>
#include<vector>

using namespace std;

struct bar
{
   bar(int) {} //implicitly constructable
};

struct bar2
{
   bar2(int) {} //implicitly constructable
};

struct foo
{
   static bar var;
};

struct foo2
{
   static bar2 var;
};

template<class T>
void dummy()
{
   decltype(T::var) meh = 43;
   if (std::is_same<decltype(T::var), bar>::value)
     std::cout << "type is bar\n";
   else if (std::is_same<decltype(T::var), bar2>::value)
     std::cout << "type is bar2\n";
}

struct X
{
   int i;
   double bar(short x) { return 33.22;}
};

// The decltype can be used to determine the type of an expression at compile-type.
int main()
{
   decltype(5) a; // x will be type of int, since 5 is int.
   decltype(a) b; // b  will be type of int, since a is defined int before.
   b = 10;
   auto z = b; // z would be int

   cout << z << endl;

   dummy<foo>(); //meh is of type bar
   dummy<foo2>(); //meh is of type bar2

   //of int
   std::vector<decltype(X::i)> v;

   //declaring member function pointer
   using memFuncPtr = decltype(&X::bar); //instead of doing double X::(*bar)(short);

   return 0;
}
