#include <iostream>
#include <vector>
#include <algorithm> //for std::ranges

int main()
{
    std::vector v = { 1, 2, 3, 4 ,5 };

    //introduced in C++20    
    auto has_odd_number = std::ranges::any_of(v, [](int x) {
        return x % 2 == 1;
    });

    std::cout << "v has odd number: " << has_odd_number << std::endl;
    return 0;
}