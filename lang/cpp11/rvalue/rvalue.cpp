#include <iostream>

using namespace std;
#define F cout << __PRETTY_FUNCTION__ << std::endl

/*
    if x is any type, then x&& is called an rvalue reference to x. 
    ordinary reference x& is now called lvalue reference.
*/

//can call  lvalue or rvalue
void foo(const int &x)
{
    F;
}

void foo(int &&x)
{
    F;
}

int foobar()
{
    return 10;
}

int &foobar2()
{
    static int x = 1;
    return x;
}

int main()
{
    foo(1); //calls foo(int&&)
    foo(foobar()); //calls foo(&&)
    int x {1};
    foo(x); //calls foo(const int&)

    foo({1}); //since {1} is rval, foo(&&)
    
    foo(std::move(x)); //calls foo(&&)

    foo(foobar2()); //calls foo(&), since foobar2() is lvalue, foobar2() = 10;
    const int a {1};
    foo(a); //call foo(const int&)

    foo(1 + 3);
    
    return 0;
}