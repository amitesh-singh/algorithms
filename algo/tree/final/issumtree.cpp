#include <iostream>
#include "tree.h"


struct mytree: public myds::tree<int, myds::basicnode<int> >
{
    using node = myds::basicnode<int>;
    private:
   

    public:

    int  makesumtree(node *&p)
      {
         if (p == nullptr) return 0;
         if (p->left == nullptr && p->right == nullptr)
           return p->data;

         p->data = makesumtree(p->left) +  makesumtree(p->right);
         return p->data;
      }

    bool issumtree(node *p)
      {
         if (p == nullptr) return false;
         if (p->left == nullptr && p->right == nullptr)
           return true;
         else if (p->left && p->right == nullptr)
           {
              if (p->data == p->left->data)
                return true;
              else return false;
           }
         else if (p->right && p->left == nullptr)
           {
              if (p->data == p->right->data)
                return true;
              else return false;
           }
         else if (p->left && p->right)
           {
              if (p->data == p->left->data + p->right->data)
                return true;
              else return false;
           }

         return issumtree(p->left) && issumtree(p->right);
      }
};

#include <ctime>

int main()
{
    std::srand(std::time(nullptr));
    mytree mt;

    for (int i = 0; i < 40; ++i)
        mt.insert(std::rand() % 101);

    //make it sumtree
    mt.print();
    std::cout << "is sum tree: " << mt.issumtree(mt.root) << std::endl;
    mt.makesumtree(mt.root);
    mt.print();


    std::cout << "is sum tree: " << mt.issumtree(mt.root) << std::endl;

    return 0;
}
