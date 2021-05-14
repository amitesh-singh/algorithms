#include "tree.h"

#include <ctime>

struct mytree: public myds::tree<int>
{
   void _liftTraverse(node *&p, int k)
     {
        if (p == nullptr || k == 0)
          {
             return;
          }
        _liftTraverse(p->parent, --k);
        std::cout << p->data << std::endl;
     }

   void uptraverse(node *p, int k)
     {
        _liftTraverse(p, k);
     }
};

int main()
{
   srand(time(nullptr));

   myds::tree<int> t = {20, 21, 22};
   t.insert(10);
   t.insert(11);
   t.insert(12);
   for (int i = 0; i < 25; ++i)
     {
        t.insert(i);
     }

   myds::tree<int>::node *ptr = t.search(11);
   std::cout << "found " << ptr->data  << " parent: " << ptr->parent->data << std::endl;

   t.inorder();

   mytree mt;
   mt.insert(10);
   mt.insert(9);
   mt.insert(11);
   mt.insert(12);
   mt.insert(13);

   using treenode = myds::tree<int>::node;
   treenode *p = mt.search(13);

   std::cout << "up traverse: \n";
   mt.uptraverse(p->parent, 10);

   return 0;
}
