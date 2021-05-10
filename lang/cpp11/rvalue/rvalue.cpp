#include <iostream>

using namespace std;
#define F cout << __PRETTY_FUNCTION__ << std::endl

/*
    if x is any type, then x&& is called an rvalue reference to x. 
    ordinary reference x& is now called lvalue reference.
*/

/*
 
   //this can only call lvalue
   void foo(int &x)
   {
   }

foo(const int &x) and foo(int &x) should not be declared together
*/

//can call  lvalue or rvalue
void foo(const int &x)
{
    F;
}

//can only call rvalue
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
   //int &x = 10; will not compile
   // can bind a lvalue to a rvalue
   const int &a1 = 10; //OK

   //foo(int &&) will given preference over foo(const int &)
   foo(1); //calls foo(int&&)
   foo(foobar()); //calls foo(&&)
   int x {1};
   foo(x); //calls foo(const int&)

   foo({1}); //since {1} is rval, foo(&&)

   foo(std::move(x)); //calls foo(&&)

   foo(foobar2()); //calls foo(&), since foobar2() is lvalue, foobar2() = 10;
   const int a {1};
   foo(a); //call foo(const int&)

   foo(1 + 3); //calls foo(int &&);
   //std::move() makes a lvalue to a rvalue
   foo(std::move(x));

   return 0;
}
