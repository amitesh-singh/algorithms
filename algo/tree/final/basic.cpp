#include "tree.h"

#include <ctime>

int main()
{
   srand(time(nullptr));

   myds::tree<int, myds::basicnode<int>> t = {20, 21, 22};
   t.insert(10);
   t.insert(11);
   t.insert(12);
   for (int i = 0; i < 25; ++i)
     {
        t.insert(i);
     }

   auto *ptr = t.search(11);
   std::cout << "found " << ptr->data  << " parent: " << ptr->parent->data << std::endl;

   t.inorder();

   return 0;
}
