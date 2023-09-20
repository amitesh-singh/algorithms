#include <iostream>
#include <concepts>

auto add(auto a, auto b)
requires (std::integral<decltype(a)> and std::integral<decltype(b)>)
{
    return a + b;
}

auto add2(std::integral auto a, std::integral auto b)
{
    return a + b;
}


template<typename T>
concept meh =  std::integral<T>;

auto add3(meh auto a, meh auto b)
{
    return a + b;
}

int main()
{
    std::cout << add(10, 20) << '\n';

    return 0;
}