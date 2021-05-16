#include "tree.h"

#include <ctime>

int main()
{
   srand(time(nullptr));

   myds::tree<int, myds::basicnode<int>> t = {20, 21, 22};
   t.insert(10);
   t.insert(11);
   t.insert(12);

   decltype(t) t1;
   t1.insert(10);
   t1.insert(11);
   t1.insert(0);
   t1.print();

   std::cout << "print iterative insert:\n";
   decltype(t) t2;
   t2.insert2(10);
   t2.insert2(11);
   t2.insert2(0);

   t2.print();

   return 0;
}
