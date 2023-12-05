#include <iostream>
#include <variant>
#include <vector>

/*
Good thing is that in traditional visitor pattern, derived classes (circle, rectangle)
has to be derived from an interface (e.g. shape) but with std::visit and std::variant,
we don't need to.

*/
class circle
{
public:
    int r;
};

class rectangle
{
public:
    int x, y, w, h;
};

using shape = std::variant<circle, rectangle>;

struct draw
{
    void operator() (circle &c)
    {
        std::cout << "drawing circle: " << c.r << std::endl;
    }
    void operator() (rectangle &r)
    {
        std::cout << "drawing rectangle: at (" << r.x << ", " << r.y << ")" << std::endl;
    }
};

struct rotate
{
    int angle;
    void operator() (circle &c)
    {
        std::cout << "rotate circle by an angle: " << angle << '\n';
    }
    void operator() (rectangle &r)
    {
        std::cout << "roate rectangle by an angle: " << angle << '\n';
    }
};

int main()
{
    std::vector<shape> shapes = {
        circle {2},
        rectangle{0, 0, 1, 1},
        circle{3}
    };

    for (auto &s: shapes) {
        std::visit(draw{}, s);
        std::visit(rotate{20}, s);
    }

    return 0;
}
