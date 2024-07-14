#include <map>
#include <iostream>

int main()
{
    // key, value
    std::map<int, int> m;

    m.insert({1, 2});
    m.insert({4, 5});
    m.insert({-1, 2});
    m.insert({5, 2});
    //the map's key is already get sorted in ascending order
    for (auto &element: m) {
        std::cout << element.first << ": " << element.second << '\n';
    }
    //output:
    // -1: 2
    // 1: 2
    // 4: 5
    // now lets try out lower_bound member function

    auto lb = m.lower_bound(2);
    // remember it's better to use std::distance() than operator-() since
    // some iterators like std::map does not implement operator-().
    auto dist = std::distance(m.begin(), lb);
    std::cout << "value at lower_bound(2): " << (*lb).first << std::endl;
    std::cout << "lower_bound(2): " << dist << std::endl;

    lb = m.upper_bound(2);
    dist = std::distance(m.begin(), lb);
    std::cout << "value at upper_bound(2): " << (*lb).first << std::endl;
    std::cout << "upper_bound(2): " << dist << std::endl;
    return 0;
}