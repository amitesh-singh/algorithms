#include <iostream>

using namespace std;
template <typename T1, typename T2>
auto compose(T1 t1, T2 t2) -> decltype(t1 + t2)
{
   return t1+t2;
}

// The auto keyword tells the compiler to infer the type of the variable from its initializer.
int main()
{
   auto x = 5; // x type would be int
   auto y = 5.5; // y - double
   auto c = "hello"; // c - const char *
   auto a = x; // a - int

   auto v = compose(2, 3.14); // v's type is double

   cout << c << endl;
   cout << v << endl;

   return 0;
}
