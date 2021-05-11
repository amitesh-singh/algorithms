#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
    std::vector<int> v;
    
    for (int i = 0; i < 10; ++i)
        v.push_back(i);
    
    for(auto &x: v)
        std::cout << x << ", ";
    std::cout << std::endl;

    std::random_shuffle(v.begin(), v.end());
    for(auto &x: v)
        std::cout << x << ", ";
    std::cout << std::endl;

    return 0;
}