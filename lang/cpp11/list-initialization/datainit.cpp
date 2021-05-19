#include <iostream>

class A
{
    int a{1};
    int b = 0;
    public:
    int getA() {return b;}
};

int main()
{
    A aa;
    std::cout << "a: " << aa.getA() << std::endl;
    return 0;
}