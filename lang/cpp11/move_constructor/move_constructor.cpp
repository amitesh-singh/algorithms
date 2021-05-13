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

void f(A &&rval)
{
    rval.print();
    std::cout << "printed\n";
}
int main()
{
    A a1(2);
    A a2(3);
    A a3(4);
    
    //calls A(A &&);
    A a4 = std::move(a1);
    //a1 is set to 0 now.. not usable.
    //Calls A &operator=(A &&rhs)
    a3 = std::move(a2);
    //a2 is unusable now.

    std::vector<A> v;
    //takes rvalue.
    v.emplace_back(std::move(a4)); //a4.a is nullptr here
    a4.print();
    v.emplace_back(A(10));
    f((A(11)));
    std::cout << "meh!\n";
    return 0;
}