#include <iostream>
#include <any>

struct A
{
 int a{2};
};

int main()
{
    std::any data;
    data = 2;

    //to print it, we need to cast it.
    int x = std::any_cast<int> (data);
    std::cout << x << std::endl;

    data = std::string("ami");
    std::string s = std::any_cast<std::string>(data);
    std::cout << s << std::endl;

    A aa;
    std::any data2 = aa;

    A &a1 = std::any_cast<A&>(data2);
    std::cout << a1.a << std::endl;

    return 0;
}