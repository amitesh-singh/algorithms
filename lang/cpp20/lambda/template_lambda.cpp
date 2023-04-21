#include <iostream>

auto main()->int
{
    auto sum = []<typename T, typename U>(const T& a, const U& b) {
         return a + b;
    };

    std::cout << sum(1, 1) << "," << sum(0.1, 1) << sum(2, 3) << std::endl;

    auto sum2 = [](auto&&... args) {
         return (args + ...);
    };

    std::cout << sum2(1, 1, 2.2) << "," << sum2(2, 4, 5.5, 5.5) << std::endl;
    return 0;
}
