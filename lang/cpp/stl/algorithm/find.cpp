#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

//std::find and std::find_if example.
struct cell
{
    int x, y;
    bool isVisited;

    //we need this for making std::find to work.
    bool operator ==(const cell &rhs)
    {
        return (x == rhs.x) and (y == rhs.y);
    }
};


int main()
{
    std::vector<cell> cells = {{5, 9, true}, {6,8, false}, {3, 4, false}};
    
    cell c = {6, 8, false};

    auto ret = std::find(std::begin(cells), std::end(cells), c);
    if (ret == cells.end())
    {
        std::cerr << "Not found\n";
    }
    else
    {
        std::cout << "Found\n";
    }
    // lambda example
    //std::find won't work with lambda function.

  
    //find_if() example.
    ret = std::find_if(std::begin(cells), std::end(cells), [](const cell &c)->bool {
        return c.x % 2 == 0;
    });

     if (ret == cells.end())
    {
        std::cerr << "Not found\n";
    }
    else
    {
        std::cout << "Found: " << ret->x << "\n";
    }

    //use find_if with lambda

    ret = std::find_if(std::begin(cells), std::end(cells), [&c](const cell &x)->bool
    {
        return (c.x == x.x and c.y == x.y); 
    });

    if (ret == cells.end())
    {
        std::cerr << "Not found\n";
    }
    else
    {
        std::cout << "Found: " << ret->x << "\n";
    }
    return 0;
}