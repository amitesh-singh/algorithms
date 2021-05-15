#include <iostream>
#include "tree.h"


struct mytree: public myds::tree<int, myds::basicnode<int> >
{
    using node = myds::basicnode<int>;
    private:
   

    void _printgivenlevel(node *p, int level)
    {
        if (!p) return;
        if (level == 1) std::cout << p->data << std::endl;
        else if (level > 1)
        {
            _printgivenlevel(p->left, level - 1);
            _printgivenlevel(p->right, level - 1);
        }
    }
    public:
    void bfs()
    {
        int levels = height();
        for (int i = 1; i <= levels; ++i)
            _printgivenlevel(root, i);
    }
  
};

#include <ctime>

int main()
{
    std::srand(std::time(nullptr));
    mytree mt;
    for (int i = 0; i < 40; ++i)
        mt.insert(std::rand() % 101);
    mt.print();
    
    mt.bfs();
    
    return 0;
}