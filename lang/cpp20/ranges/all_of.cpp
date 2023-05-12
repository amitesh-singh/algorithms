#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector v = { 1, 2, 3, 4, 5};
    
    //introduced in C++20    
    bool all_odd_numbers = std::ranges::all_of(v, [](int x) {
        return x % 2 == 1;
    });

    std::cout << "is all odd numbers: " << all_odd_numbers << std::endl;
    return 0;
}