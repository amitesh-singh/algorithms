#include <iostream>

using namespace std;

// The auto keyword tells the compiler to infer the type of the variable from its initializer.
int main()
{
   auto x = 5; // x type would be int
   auto y = 5.5; // y - double
   auto c = "hello"; // c - const char *
   auto a = x; // a - int

   cout << c << endl;

   return 0;
}
