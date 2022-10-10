#include <iostream>
//find if two given rectangles overlaps to each other.

// logic:
// min of large coordinates > max of small coordinates

struct rect
{
    int x1, y1; //bottom left 
    int x2, y2; //top right
};

bool is_overlap(rect rect1, rect rect2)
{
    bool isWidthPositive = std::min(rect1.x2, rect2.x2) > std::max(rect1.x1, rect2.x1);
    bool isHeightPositive = std::min(rect1.y2, rect2.y2) > std::max(rect1.y1, rect2.y1);
    
    return isWidthPositive and isHeightPositive;
}

int main()
{
    rect r1 {0, 0, 2, 2};
    rect r2 {0, 0, 3, 3};

    std::cout << is_overlap(r1, r2) << std::endl;

    std::cout << is_overlap(rect{0, 0, 2, 2}, rect{3, 3, 4, 4}) << std::endl;
    return 0;
}