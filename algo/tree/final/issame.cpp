#include <iostream>
#include "tree.h"
#include <ctime>
#include <future>

using tree = myds::tree<int, myds::basicnode<int>> ;
using node = myds::basicnode<int>;
bool issame(node *p1, node *p2)
{
    if (!p1 && !p2)
      return true;
    else if (!p1 && p2)
      return false;
    else if (p1 && !p2)
      return false;
    else if (p1 && p2)
      return (p1->data == p2->data && issame(p1->left, p2->left) && issame(p1->right, p2->right));

    return false;
}

bool issame(tree &tr1, tree &tr2)
{
  return issame(tr1.root, tr2.root);
}

int main()
{
   std::srand(std::time(nullptr));
   tree t;

   for (int i = 0; i < 40; ++i)
     t.insert(std::rand() % 101);

   auto t2 = t; //copy of t2

   std::cout << "equal check: " << issame(t, t2) << std::endl;
   std::cout << "native code: " << (t == t2) << std::endl;
   using fptr = bool (*)(node *, node *);

   fptr f = issame;
   //can we do better and use thread for checking left and right subtree simultaneously? possible
   auto leftSubtreeWorker = std::async(std::launch::async, (bool (*)(node *, node *)) (issame), t.root->left, t2.root->left);
   auto rightSubtreeWorker = std::async(std::launch::async, f, t.root->right, t2.root->right);

   std::cout << "waiting for thread to do the job " << std::endl;
   auto l = leftSubtreeWorker.get();
   auto r  = rightSubtreeWorker.get();
   std::cout << "threaded check: " << ((t.root->data == t2.root->data) && l && r) << std::endl;

   return 0;
}
