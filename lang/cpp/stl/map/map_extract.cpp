#include <map>
#include <iostream>


int main()
{
    std::map<int, int> dict = { {1, 2}, {2, 3} };

    // task is to change the existing key

    auto elem = dict.extract(1);
    elem.key() = 10;

    for (const auto &el: dict) {
        std::cout << el.first << ", ";
    }
    std::cout << '\n';
    
    return 0;
}