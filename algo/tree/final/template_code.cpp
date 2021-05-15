#include <iostream>
#include "tree.h"


struct mytree: public myds::tree<int, myds::basicnode<int> >
{
    using node = myds::basicnode<int>;
    private:
   

    public:
  
};

#include <ctime>

int main()
{
    std::srand(std::time(nullptr));
    mytree mt;
    std::cout << "before loop\n";
    for (int i = 0; i < 40; ++i)
        mt.insert(std::rand() % 101);
   

    
    return 0;
}