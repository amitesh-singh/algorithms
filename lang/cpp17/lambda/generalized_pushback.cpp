#include <iostream>
#include <vector>

//refer https://www.youtube.com/watch?v=v5tLFRfktWA

template<typename container, typename... args>
void generalized_push_back(container &c, args&& ... t) {
    (c.push_back(std::forward<args>(t)), ...);
}

int main()
{
    std::vector<int> v;
    auto push_back = [](auto &&v2, auto && ... args) {
        (v2.push_back(std::forward<decltype(args)>(args)), ...);
    };  

    push_back(v, 1, 2, 3, 4);
    generalized_push_back(v, 5, 6, 7, 8);

    for (const auto &n: v) {
        std::cout << n << ',';
    }
    std::cout << '\n';

    return 0;
}