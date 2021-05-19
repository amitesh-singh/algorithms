#include "tree.h"
#include <vector>
#include <ctime>

 template <class T>
   struct basicnode
    {
                 basicnode<T> *left, *right;
                 T data;
                 basicnode<T> *parent;
                 int children_count {0};
                 basicnode(const T &d): data(d), left(nullptr), right(nullptr), parent(nullptr) {}
    };

class mytree: public myds::tree<int, basicnode<int>>
{
    using node = basicnode<int>;
    void _getRandom(node *p, std::vector<node *> &v)
    {
        if (p == 0) return;
        v.push_back(p);
        _getRandom(p, v);
        _getRandom(p, v);
        std::cout << "meh\n";
    }
    public:
    node *getRandom()
    {
        std::vector<node *> v;
        _getRandom(root, v);
        int nodeCount = v.size();
        return v[rand() % nodeCount];
    }
};

int main()
{
    std::srand(std::time(nullptr));
    mytree mt;
    std::cout << "nodei s crated\n";
    for (int i = 0; i < 10; ++i)
        mt.insert(rand() % 101);
    
    mt.print();
    std::cout << "print something\n\n";
    basicnode<int> *n = mt.getRandom();
    std::cout << "random node: " << n->data << std::endl;
    //std::cout << "\n\nrandom node: " << mt.getRandom()->data << std::endl;
    std::cin.get();
    return 0;
}
