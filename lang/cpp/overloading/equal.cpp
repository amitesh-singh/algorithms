#include <iostream>

#define F std::cout << __PRETTY_FUNCTION__ << std::endl

class A
{
    int a;
    public:
    // A aa = 2; //not allowed
    explicit A(int &&_a): a(_a) {F;}
    A(const A &) = delete;
    A &operator=(const A &rhs)
    { 
        F;
        a = rhs.a;
        return *this;
    }

    A &operator=(int &&v)
    {
        F;
        a = v;
        return *this;
    }

    int &getA()
    {
        return a;
    }

    operator int() const
    {
        F;
        return a;
    }
};

int main()
{
    A aa(2);
    aa = 3;

    std::cout << aa.getA() << std::endl;
    A aa2(4);
    //aa = aa2;
    aa = aa2 = 5;
    std::cout << int(aa) << std::endl;
    
    return 0;
}