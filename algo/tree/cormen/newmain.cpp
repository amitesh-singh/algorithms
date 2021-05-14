#include "tree.h"

#include <ctime>

int main()
{
   srand(time(nullptr));

   myds::tree<int> t = {20, 21, 22};
   t.insert(10);
   t.insert(11);
   t.insert(12);

   t.inorder();
   return 0;
}
