#include <iostream>

using namespace std;

// The decltype can be used to determine the type of an expression at compile-type.
int main()
{
   decltype(5) a; // x will be type of int, since 5 is int.
   decltype(a) b; // b  will be type of int, since a is defined int before.
   b = 10;
   auto z = b; // z would be int

   cout << z << endl;

   return 0;
}
