#include <iostream>
#include "tree.h"
#include <queue>


struct mytree: public myds::tree<int, myds::basicnode<int> >
{
    using node = myds::basicnode<int>;
    private:
    void _printgivenlevel(node *p, int level, int &actuallevel)
    {
        if (!p) return;
        if (level == actuallevel) std::cout << p->data << std::endl;

        _printgivenlevel(p->left, level + 1, actuallevel);
        _printgivenlevel(p->right, level + 1, actuallevel);
    }
    public:
    void bfs()
    {
        int levels = height();
        for (int i = 1; i <= levels; ++i)
            _printgivenlevel(root, 1, i);
    }

    void bfs2()
      {
         std::queue<node *> q;
         node *p = root;

         q.push(p);
         while (!q.empty())
           {
              node *curr = q.front();
              q.pop();
              std::cout << curr->data << ", ";

              if (curr->left) q.push(curr->left);
              if (curr->right) q.push(curr->right);
           }
         std::cout << '\n';
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
    std::cout << "bfs using queue:\n";
    mt.bfs2();
    
    return 0;
}
