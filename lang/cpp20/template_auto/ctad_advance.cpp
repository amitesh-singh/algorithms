#include <iostream>

template<typename... Ts>
struct overload: Ts...
{
    using Ts::operator()...;
};

template<typename... Ts>
overload(Ts...)->overload<Ts...>;

int main()
{
    auto f1 = [](int x) {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    };

    auto f2 = []() {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    };

    //below line won't compile in c++17, compiles in c++20 though.
    //we need CTAD
    overload o{f1, f2};

    return 0;
}