#include <iostream>
#include "tree.h"
#include <vector>

template<class T>
struct mynode
{ 
    mynode<T> *left, *right;
    T data;
    mynode<T> *parent;
    mynode(const T &d): data(d), left(nullptr), right(nullptr), parent(nullptr) {}

    //new variable:
    std::vector<mynode<T> *> parents;
};

struct mytree: public myds::tree<int, mynode<int>>
{
    using tnode = mynode<int>;
    void go_up(tnode *&p)
    {
        if (p == nullptr)
            return;
        std::cout << p->data << std::endl;
        go_up(p->parent);
    }
};
#include <ctime>
int main()
{
    mytree mt;
    srand(time(nullptr));
    for (int i = 0; i < 100; ++i)
        mt.insert(rand() % 101);
    mytree::tnode *p = mt.search(90);
    if (p)
        mt.go_up(p->parent);

    mt.print();

    return 0;
}


