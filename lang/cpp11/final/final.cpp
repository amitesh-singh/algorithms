/*
 * Specifies that a virtual function cannot be overridden in a derived class or that a class cannot be inherited from.

struct A {
  virtual void foo();
};

struct B : A {
  virtual void foo() final;
};

struct C : B {
  virtual void foo(); // error -- declaration of 'foo' overrides a 'final' function
};

Class cannot be inherited from.

struct A final {};
struct B : A {}; // error -- base 'A' is marked 'final'
*/
#include <iostream>
using namespace std;

struct A
{
   virtual void foo();
};

struct B: public A
{
   virtual void foo() final;
};

struct C: public B
{

   virtual void foo(){}
};

int main()
{
   return 0;
}

