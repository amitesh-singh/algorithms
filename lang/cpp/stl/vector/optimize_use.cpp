#include <iostream>
#include <vector>

#define F std::cout << __PRETTY_FUNCTION__ << std::endl

class A
{
    int a, b, c;
    public:
    A(int _a, int _b, int _c): a(_a), b(_b), c(_c) 
    {
        F;
    }
    A(const A&rhs): a(rhs.a), b(rhs.b), c(rhs.c)
    {
        F;
    }
    A(A &&rval): a(rval.a), b(rval.b), c(rval.c)
    {
        F;
    }
};

int main()
{
    //since we know how much data is allocated.
    std::vector<A> v;
    v.reserve(3); //reserve the capacity for 3 data

    v.push_back({1, 2, 3});
    
    v.emplace_back(1, 2, 3); //-> best way to use it.
    
    v.emplace_back(A(1, 2, 3));
    return 0;
}