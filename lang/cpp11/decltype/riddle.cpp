#include <iostream>

bool g() {
 double x;
 auto f = [x=1]() -> decltype(x) {return 1.1;};
 return f() > 1; // A
}

int main()
{
    std::cout << g() << std::endl;
    return 0;
}