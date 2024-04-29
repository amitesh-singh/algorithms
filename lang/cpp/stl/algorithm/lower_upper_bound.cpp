#include <algorithm>
#include <iostream>
#include <array>

int main()
{
    std::array<int, 11> arr { 1, 2, 3, 3, 3, 4, 4, 5, 6, 9, 9};

    // lets find the lower bound for 3 which is basically <= 3
    // x <= 3 ---> lower bound, remember this
    auto itr = std::lower_bound(std::begin(arr), std::end(arr), 3);

    if (itr != arr.end()) {
        std::cout << "index of 3 is " << (itr - arr.begin()) << std::endl;
    }
    
    // lets find the upper bound for 3 which is basically >= 3
    // x >= 3 - upper bound, remember this
    itr = std::upper_bound(std::begin(arr), std::end(arr), 3);
    if (itr != arr.end()) {
        std::cout << "upper bound for 3 is " << itr - arr.begin() << std::endl;
    }

    return 0;
}

