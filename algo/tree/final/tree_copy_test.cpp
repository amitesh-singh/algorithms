#include <iostream>
#include "tree.h"

#include <ctime>

int main()
{
    std::srand(std::time(nullptr));
    myds::tree<int, myds::basicnode<int> > t;

    for (int i = 0; i < 40; ++i)
        t.insert(std::rand() % 101);

    decltype(t) t2;
    t2 = t; 
    t.print();
    t2.print();
    
    return 0;
}