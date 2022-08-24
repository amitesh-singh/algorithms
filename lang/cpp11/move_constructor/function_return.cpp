#include <iostream>

#define F std::cout << __PRETTY_FUNCTION__ << '\n'
class A
{
   int a;
  public:
      A(int x): a(x) { F; }
      A(const A &aa): a(std::move(aa.a)) { F; }
      A(A &&aa): A(aa) {F; }
      ~A() { F; }
};

A make_A(int a)
{
   return A(a);
}

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

int main()
{
   //https://en.wikipedia.org/wiki/Copy_elision#RVO
   // A(const A&) won't get called due to return type optimization.
   A aa = A(10);

   std::cout << "is lvalue: " << is_lvalue(A(20)) << '\n';
   return 0;
}
