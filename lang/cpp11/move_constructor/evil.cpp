#include <iostream>
#define F std::cout << __PRETTY_FUNCTION__ << std::endl

struct S
{
    int x;
    S &operator=(S &&rhs)
    {
        F;
        rhs.x = x;
        return *this;
    }

    S &operator=(S &rhs)
    {
        F;
        rhs.x = x;
        return *this;
    }
};

int main()
{
    S foo{7};
    S bar {42};
    S{13} = std::move(foo);
    bar = foo;

    std::cout << foo.x << std::endl;
    std::cout << bar.x << std::endl;
    return 0;
}