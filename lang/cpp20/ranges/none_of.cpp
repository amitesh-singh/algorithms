#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector v { 2, 4, 6, 8 };

    bool no_odd_number = std::none_of(std::begin(v), std::end(v), [](int x) {
        return x % 2 == 1;
    });

    std::cout << "has no odd number: " << no_odd_number << std::endl;
    return 0;
}