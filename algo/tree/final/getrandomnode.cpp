#include "tree.h"
#include <vector>
#include <ctime>
#include <thread>
#include <condition_variable>
#include <mutex>

 template <class T>
   struct basicnode
    {
                 basicnode<T> *left, *right;
                 T data;
                 basicnode<T> *parent;
                 int children_count {0};
                 basicnode(const T &d): data(d), left(nullptr), right(nullptr), parent(nullptr) {}
                 int getChildrenCount()
                 {
                     return children_count - 1;
                 }
    };

using node = basicnode<int>;
class mytree: public myds::tree<int, basicnode<int>>
{
    
    std::once_flag flag;


    void _getRandom(node *p, std::vector<node *> &v)
    {
        if (p == 0) return;
        v.push_back(p);
        _getRandom(p->left, v);
        _getRandom(p->right, v);
    }
    public:
    node *getRandom()
    {
        static std::vector<node *> v;
        static int nodeCount;
        std::call_once(flag, [&]() {
            _getRandom(root, v);
         nodeCount = v.size();
        });
        
        return v[rand() % nodeCount];
    }

    void _getRandom2(node *p, int &c, int r, node *&res)
    {
        if (p == nullptr) return;
        if (c++ == r) {
            res = p;
            return;
        }
        _getRandom2(p->left, c, r, res);
        _getRandom2(p->right, c, r, res);

    }
//without vector
    node *getRandom2()
    {
        int r = rand() % size();
        node *res = nullptr;
        int c = 0;
        _getRandom2(root, c, r, res);

        return res;
    }

    int   populateChildrenCount(node *&p)
    {    
        if (p == nullptr) return 0;
       // if (!p->left && !p->right) {p->children_count = 1; return 1;}
       
         p->children_count = populateChildrenCount(p->left) + populateChildrenCount(p->right) + 1;
         return p->children_count;
    }

    int children(node *p)
    {
        if (!p) return 0;
        return p->children_count;
    }

    node *getRandom3(node *p, int count)
    {
        if (p == nullptr) return nullptr;
        if (count == children(p->left))
            return p;
        if (count < children(p->left))
            return getRandom3(p->left, count);
        return getRandom3(p->right, count - children(p->left) - 1);
    }

    node *getRandom3()
    {   
        int count = rand() % root->children_count;
        
        return getRandom3(root, count);
    }



};

void printChildren(node *p)
{
    std::cout << p->children_count << std::endl;
}

int main()
{
    std::srand(std::time(nullptr));
    mytree mt;
    
    for (int i = 0; i < 10; ++i)
        mt.insert(rand() % 101);
    
    mt.print();
    basicnode<int> *n = mt.getRandom();
   
    mt.populateChildrenCount(mt.root);

    mt.print(printChildren);
    n = mt.getRandom2();
    std::cout << "random node2 : " << n->data << std::endl;
    n = mt.getRandom3();
    std::cout << "random node 3: " << n->data << std::endl;

    return 0;
}
