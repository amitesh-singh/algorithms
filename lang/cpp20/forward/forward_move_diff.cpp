#include <iostream>
/*
 *
 * std::move takes an object and allows you to treat it as a temporary (an rvalue). Although it isn’t a semantic requirement, typically a function accepting a reference to an rvalue will invalidate it. When you see std::move, it indicates that the value of the object should not be used afterwards, but you can still assign a new value and continue using it.

std::forward has a single use case: to cast a templated function parameter (inside the function) to the value category (lvalue or rvalue) the caller used to pass it. This allows rvalue arguments to be passed on as rvalues, and lvalues to be passed on as lvalues, a scheme called “perfect forwarding.”
 * */
void overload(const int &arg)
{
   std::cout << "by lvalue\n";
}

void overload(int &&arg)
{
   std::cout << "by rvalue\n";
}

template<typename T>
void forwarding(T &&arg)
{
   overload(std::forward<T>(arg));
   overload(std::move(arg));
}

int main()
{
   forwarding(5);
   int x = 5;
   forwarding(x);
   return 0;
}
