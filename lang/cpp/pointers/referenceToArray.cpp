#include <iostream>

void f(auto (&ref))
{
    for (auto &x: ref)
        std::cout << x << "->";
    std::cout << std::endl;
}

int main()
{
    int a[] = {1, 2 , 3, 44};
    //reference to an array
    //int (&ref)[sizeof(a)/sizeof (*a)] = a;
    auto (&ref) = a; 
    for (auto &x: ref)
        std::cout << x << "->";
    std::cout << std::endl;
    f(a);
    return 0;
}