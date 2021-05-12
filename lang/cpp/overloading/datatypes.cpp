#include <iostream>

//we can overload datatypes now in C++
//search "user-defined conversion function" on google.
class A
{
    int a;
    public:
    A(int &&x): a(x)
    {
    }
    A(const int &x): a(x) {}
    operator int() const
    {
        return a;
    }

    operator bool () const
    {
        return a > 0;
    }

    operator std::string () const
    {
        return "Slim Sheddy";
    }

    void print()
    {
        std::cout << a << std::endl;
    }
};

class B
{
    int a;
    public:
    B(const int &x): a(x) {}
    operator A()
    {
        return A(a);
    }
};

void onlyACallsMe(A &&aa)
{
    aa.print();
}

int main()
{
    A aa (4);
    std::string myname = aa;
    std::cout << myname << std::endl;
    std::cout << int(aa) << std::endl;
    if (aa)
    {
        std::cout << "aa > 0" << std::endl;
    }

    std::cout << "I am " << std::string(aa) << std::endl;

    B bb(5);

    onlyACallsMe(A(bb));
    
    return 0;
}