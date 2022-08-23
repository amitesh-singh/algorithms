#include <iostream>
#include <vector>

#define F std::cout << __PRETTY_FUNCTION__ << std::endl
/*
in other words, when you use std::move(x), you're allowing the compiler to cannibalize x.
 Thus if x has, say, its own buffer 
in memory - after std::move()ing the compiler can have another object own it instead
*/

class A
{
    int *a;
    public:
    A() = delete;
    A(int x): a(new int(x))
    {
        F;
    }
    A(const A &)  = delete;
    //move ctor
    A(A &&rhs)
    {
        F;
        a = rhs.a;
        rhs.a = nullptr;
    }

    //move = operator
    A &operator=(A &&rhs)
    {
        if (this == &rhs) return *this;
        delete a;
        a = rhs.a;
        rhs.a = nullptr;
        F;
        return *this;
    }

    ~A()
    {
        delete a;
        a = nullptr;
        F;
    }
    void print()
    {
        std::cout << a << std::endl;
    }
};

template<typename T>
bool is_lvalue(T &) {
     return true;
}

template<typename T>
bool is_lvalue(T &&) {
     return false;
}
class B
{
   A aa;
  public:
      //we still need std::move or std::forward<A>
      B(A &&a): aa(std::forward<A>(a)) { std::cout << "is_lvalue: " << is_lvalue(a) << '\n'; }
      //B(A &&a): aa(a) {}

      //B(A &a): aa(std::move(a)) {}
};

int main()
{
    B bb(A(10));
    //A aa(11);

    //B bb2(aa);
    return 0;
}
