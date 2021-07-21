#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <algorithm>

struct cell
{
    int x, y;
    bool isVisited;

    void print()
    {
        std::cout << "x: " << x << " y: " << y << " visited: " << isVisited << std::endl;
    }
};
int main()
{
    std::vector<int> v {10, 220, 23, 45, 450, -1};
    auto minItr = std::min_element(begin(v), end(v));
    auto maxItr = std::max_element(begin(v), end(v));

    std::cout << "min element is: " << *minItr << std::endl;
    std::cout << "max element is: " << *maxItr << std::endl;
    int pos = minItr - v.begin();

    //minmax type is pair<std::vector<int>::iterator, std::vector<int>::iterator> >
    auto minmax = std::minmax_element(v.begin(), v.end());
    std::cout << "pair<int, int> minmax = " << *minmax.first << ", "
             << *minmax.second << std::endl;
    int minPos = minmax.first - v.begin();
    int maxPos = minmax.second - v.begin();

    std::pair<int, int> minmaxPair;
    minmaxPair = std::minmax({10, 23, 343, 344, 1});
    std::cout << minmaxPair.first << ", " << minmaxPair.second << std::endl;

    std::cout << "min(10, 20): " << std::min(10, 20) << std::endl;
    std::cout << "max(20, 34): " << std::max(20, 34) << std::endl;

    //custom std::max/min
    cell c1 {2, 5, true};
    cell c2 {5, 5, false};
    cell c3 {6,8, true};

    cell res = std::max(c1, c2, [](const cell &lhs, const cell &rhs)->bool 
    {
        return lhs.x == rhs.x and rhs.y == rhs.y;
    });

    res.print();

    return 0;
}