#include <iostream>

int main()
{
    constexpr auto calc_square = [](auto x) constexpr { return x*x;};

    constexpr int ret = calc_square(10);
    std::cout << ret << '\n';

    return 0;
}
