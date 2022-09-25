#include <iostream>
/// @brief add -std=c++20 for compiling the code
/// @return 
int main()
{
    const auto print = [](auto... args) {
        (std::cout << ... << args) << '\n';
    };

    print("hello", 1, 2, 3, 10.5f);

    const auto print2 = [](auto... args) {
        ([args](){ std::cout << args << ',';}(), ...);
        std::cout << '\n';
    };
    print2("hello", 1, 2, 3, 10.5f);

    const auto print3 = [](auto... args) {
        ([args]() {std::cout << ',' << args;}(), ...);
    };

    print3("hello", 1, 2, 3, 10.5f);

    const auto print4 = [](auto... args) {
        ((std::cout << ',' << args), ...);
        std::cout << '\n';
    };
    print4("hello", 1, 2, 3, 10.5f);

    return 0;
}