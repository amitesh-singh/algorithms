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
        t.insert(rand() % 31);
     }

   auto *ptr = t.find(11);
   if (ptr)
      std::cout << "found " << ptr->data  << " parent: " << ptr->parent->data << std::endl;

   t.inorder();
   t.print();
   std::cout << "nodes  count: " << t.size() << std::endl;
   std::cout << "height: " << t.height() << std::endl;

   return 0;
}
