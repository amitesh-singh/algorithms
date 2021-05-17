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
        t.insert(rand() % 131);
     }

   auto *ptr = t.find(11);
   if (ptr)
      std::cout << "found " << ptr->data  << " parent: " << ptr->parent->data << std::endl;

   t.inorder();
   t.print();
   std::cout << "nodes  count: " << t.size() << std::endl;
   std::cout << "height: " << t.height() << std::endl;

   std::cout << "get min: " << t.getMin() << std::endl;
   std::cout << "get max: " << t.getMax() << std::endl;


   decltype(t) t1;
   t1.insert(10);
   t1.insert(11);
   t1.insert(0);
   t1.print();

   std::cout << "print iteratie insert:\n";
   decltype(t) t2;
   t2.insert2(10);
   t2.insert2(11);
   t2.insert2(0);

   t2.print();

    for (int i = 0; i < 25; ++i)
     {
        t2.insert(rand() % 131);
     }

   t2.print();
   return 0;
}
