#include <iostream>

using namespace std;

class B
{
 public:
    virtual void X() final; // // final identifier marks this function as non-overrideable
};

class D: public B
{
 public:
    virtual void X(); // // trying to override final function Base::X() will cause a compiler error
};

// final identifier marks this class as non-inheritable
class Base final
{
};

// trying to override final class Base will cause a compiler error
class Derived: public Base
{
};
int main()
{
   return 0;
}
