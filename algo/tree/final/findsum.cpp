#include <iostream>
#include "tree.h"


struct mytree: public myds::tree<int, myds::basicnode<int> >
{
    using node = myds::basicnode<int>;
    private:
    size_t _find_sum(node *p)
    {
        if (!p) return 0;
        return p->data + _find_sum(p->left) + _find_sum(p->right);
    }

    size_t _getCount(node* p)
    {
        if (!p) return 0;
        return _getCount(p->left) + _getCount(p->right) + 1;
    }

    public:
    size_t find_sum()
    {
        return _find_sum(root);
    }

    size_t getCount()
    {
        return _getCount(root);
    }
};
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));
    mytree mt;
    std::cout << "before loop\n";
    for (int i = 0; i < 40; ++i)
        mt.insert(std::rand() % 101);
    std::cout << "printing\n";
    mt.print();
    std::cout << mt.find_sum() << std::endl;
    std::cout << "nodes count: " << mt.getCount() << std::endl;
    return 0;
}