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

   // lambda function
   auto f = [](int a, int b) ->int { return a + b; };

   cout << "Sum = " << f(10, 20) << "\n";
   cout << c << endl;
   cout << v << endl;
   //in C++14
   auto f1 = [](auto a, auto b)->auto {return a + b;};
   cout << "sum1 = " << f1(10, 11) << std::endl;

   return 0;
}
