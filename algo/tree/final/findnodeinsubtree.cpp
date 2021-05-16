#include <iostream>
#include "tree.h"
#include <ctime>
#include <thread>
#include <future>
#include <optional>

using tree = myds::tree<int, myds::basicnode<int>> ;
using node = myds::basicnode<int>;


struct res
{
   node *ptr;
   std::optional<std::string> pos;
};
void _findsubnode(node *root, res &r, int k, std::once_flag &flag1)
{
   if (root == nullptr) return;
   if (k < root->data)
     {
        std::call_once(flag1, [&r]() { *r.pos = "left"; });
        _findsubnode(root->left, r, k, flag1);
     }
   else if (k > root->data)
     {
        std::call_once(flag1, [&r]() { *r.pos = "right"; });
        _findsubnode(root->right, r, k, flag1);
     }
   else
     {
        r.ptr = root;
        return;
     }
}

res findsubnode(node *root, int k)
{
   res r = { nullptr, std::nullopt };

   /*
   if (k < root->data) *r.pos = "left";
   else if (k > root->data) *r.pos = "right";
   else *r.pos = "root";
   */
   if (k == root->data) *r.pos = "root";
   std::once_flag flag1;
   _findsubnode(root, r, k, flag1);
   return r;
}
int main()
{
   std::srand(std::time(nullptr));
   tree t;

   t.insert(5);
   t.insert(4);
   t.insert(6);
   t.insert(1);
   t.insert(3);
   t.insert(100);
   t.insert(9);

   t.print();

     {
        res r1 = findsubnode(t.root, 9);
        std::cout << r1.ptr->data << ": " << *r1.pos << std::endl;
        res r2 = findsubnode(t.root, 3);
        std::cout << r2.ptr->data << ": " << *r2.pos << std::endl;
     }
     {
        res r = findsubnode(t.root, 5);
        std::cout << r.ptr->data << ": " << *r.pos << std::endl;
     }

   return 0;
}
