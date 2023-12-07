#include <iostream>
#include <variant>

template<typename... Ts>
struct overload: Ts...
{
    using Ts::operator()...;
};

template<typename... Ts>
overload(Ts...)->overload<Ts...>;

int main()
{
/*
    By default, std::variant will default construct with the first of its element active.

    This can be problematic when we want to permit an empty state or the elements are expensive to 
    construct or do not support default construction.

    std::monostate can be used as the first element of a variant to get around these issues.
    */
    std::variant<std::monostate, int, float> v; //no value assigned, hence it has monostate (left most value)
    std::variant<int, float, std::monostate> v2; //no value assigned, hence its value is int (left most value)
    
    std::visit([](auto &&arg) {
        if constexpr (std::is_same_v<decltype(arg), std::monostate>) {
            std::cout << "No value\n";
        } else {
            //this won't compile, that's we need that overload struct for this
            //std::cout << arg << std::endl;
        }
    }, v);

    std::visit(overload {
        [](int x) {
            std::cout << "int\n";
        },
        [](float y) {
            std::cout << "float\n";
        },
        [](std::monostate) {
            std::cout << "not initialized\n";
        }

    }, v);

    std::visit(overload {
        [](int x) {
            std::cout << "int\n";
        },
        [](float y) {
            std::cout << "float\n";
        },
        [](std::monostate) {
            std::cout << "not initialized\n";
        }

    }, v2);

    return 0;
}