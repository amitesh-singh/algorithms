#include <iostream>
#include "tree.h"
#include <ctime>

using tree = myds::tree<int, myds::basicnode<int>> ;
using node = myds::basicnode<int>;
bool ismirror(node *p1, node *p2)
{
    if (!p1 && !p2)
      return true;
    else if (!p1 && p2)
      return false;
    else if (p1 && !p2)
      return false;
    else if (p1 && p2)
      {
         return (p1->data == p2->data && ismirror(p1->left, p2->right) && ismirror(p1->right, p2->left));
      }

    return false;
}

bool ismirror(tree &tr1, tree &tr2)
{
  return ismirror(tr1.root, tr2.root);
}

int main()
{
   std::srand(std::time(nullptr));
   tree t;

   for (int i = 0; i < 40; ++i)
     t.insert(std::rand() % 101);

   auto t2 = t; //copy of t2

   std::cout << "mirror check: " << ismirror(t, t2) << std::endl;

   return 0;
}
