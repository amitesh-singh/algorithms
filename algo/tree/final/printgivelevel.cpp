#include <iostream>
#include "tree.h"


struct mytree: public myds::tree<int, myds::basicnode<int> >
{
    using node = myds::basicnode<int>;
    private:

    void _printgivenlevel(node *p, int &&level, int &requiredLevel)
    {
        if (!p) return;
        if (level == requiredLevel) std::cout << p->data << " ";
        _printgivenlevel(p->left, level + 1, requiredLevel);
        _printgivenlevel(p->right, level + 1, requiredLevel);
    }

    public:
    void printgivenlevel(int level)
    {
        if (level > height())
        {
            std::cout << "level does not exist\n";
            return;
        }
        _printgivenlevel(root, 1, level);
    }

};
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));
    mytree mt;
    for (int i = 0; i < 10; ++i)
    {
        mt.insert(rand() % 101);
    }

    mt.print();

    mt.printgivenlevel(12);
    mt.printgivenlevel(3);
    return 0;
}
