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

    t.print();
    std::cout << "delete 12\n";
    t.erase(12);

    t.print();

    std::cout << "delete 10\n";
    t.erase(10);
    t.print();
    
    return 0;
}
