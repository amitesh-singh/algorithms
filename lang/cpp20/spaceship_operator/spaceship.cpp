#include <iostream>
#include <compare>
#include <set>

struct point
{
    int x, y;
    // implements all <, ==, >, 
    auto operator<=>(const point &rhs) const = default;
};


int main()
{
    //<=>
    int x = 10;
    auto comp = x <=> 20; //comp type is std::strong_holding
    if (comp < 0)
        std::cout << x << " is less than 20\n";
    else if (comp == 0)
        std::cout << x << " is equal to 20\n";
    else if (comp > 0)
        std::cout << x << " is greater than 20\n";

    point p1 {10, 20};
    point p2 {20, 10};

    auto comp2 = p1 < p2;
    std::cout << (comp > 0) << std::endl;

    std::set<point> s;
    s.emplace(p1);
    s.emplace(p2);
    s.emplace(point{10, 20});

    for (const auto &[x, y] : s)
    {
        std::cout << x << "," << y << '\n';
    }
    return 0;
}