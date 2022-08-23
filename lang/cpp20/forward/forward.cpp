#include <iostream>
/*
 *
 * std::move takes an object and allows you to treat it as a temporary (an rvalue). Although it isn’t a semantic requirement, typically a function accepting a reference to an rvalue will invalidate it. When you see std::move, it indicates that the value of the object should not be used afterwards, but you can still assign a new value and continue using it.

std::forward has a single use case: to cast a templated function parameter (inside the function) to the value category (lvalue or rvalue) the caller used to pass it. This allows rvalue arguments to be passed on as rvalues, and lvalues to be passed on as lvalues, a scheme called “perfect forwarding.”
 * */


//https://docs.microsoft.com/en-us/cpp/cpp/rvalue-reference-declarator-amp-amp?view=msvc-170

#define F std::cout << __PRETTY_FUNCTION__ << '\n'
template<typename T>
bool is_lvalue(T &)
{
    return true;
}

template<typename T>
bool is_lvalue(T &&)
{
   return false;
}

template<typename T>
void overload(T &&meh)
{
   F;
   std::cout << (is_lvalue(std::forward<T>(meh)) ? "lvalue" : "rvalue") << '\n';
}
template<typename T>
void forwarding(T &&arg)
{
   F;
   overload(std::forward<T>(arg));
   overload(std::move(arg));
   overload(arg);
}

int main()
{
   forwarding(5);
   int x = 5;
   std::cout << "passing int x = 5\n";
   forwarding(x);
   return 0;
}
