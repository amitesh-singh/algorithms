#include <iostream>
#include <algorithm>
#include <array>

int main()
{
    std::array<int, 5> a1 = {5, 4, 10, 20, 30};
    std::make_heap(begin(a1), end(a1));
    for (auto &x: a1)
        std::cout << x << ", ";
    std::cout << std::endl;

    std::cout << "popping up heap\n";
    std::pop_heap(a1.begin(), a1.end());

    for (auto &x: a1)
        std::cout << x << ", ";
    std::cout << std::endl;

    std::cout << "pushing\n";
    //calling std::push_heap, so that popped item will become part of heap again.
    std::push_heap(begin(a1), end(a1));
    for (auto &x: a1)
        std::cout << x << ", ";
    std::cout << std::endl;

    return 0;
}