#include "tree.h"
#include <ctime>
#include <vector>

using node = myds::basicnode<int>;

void inorder(node *root, std::vector<node *> &v)
{
   if (root == nullptr) return;
   if (root->left) inorder(root->left, v);
   v.push_back(root);
   if (root->right) inorder(root->right, v);
}

node * vec_lower_bound(std::vector<node *> &v, int key)
{
   if (v.size() == 0) return nullptr;
   int ret = -1;
   int mid, low = 0, high = v.size() - 1;

   while (low <= high)
     {
        mid = low + (high - low)/2;

        if (v[mid]->data >= key)
          {
             ret = mid;
             high = mid - 1;
          }
        else
          {
             low = mid + 1;
          }
     }
   return (ret == -1 ? nullptr : v[ret]);
}

//using inorder
node *lower_bound2(node *root, int key)
{
   if (root == nullptr) return nullptr;
   std::vector<node *> v;
   inorder(root, v);

   return vec_lower_bound(v, key);
}

//optimized
void lower_bound(node *root, int key, node *&res)
{
   if (root == nullptr) return;

   if (root->data >= key)
     {
        res = root;
        return lower_bound(root->left, key, res);
     }
   else
     {
        return lower_bound(root->right, key, res);
     }
}


int main()
{
   srand(time(nullptr));

   myds::tree<int, myds::basicnode<int>> t;
   for (int i = 0; i < 25; ++i)
     {
        t.insert(rand() % 131);
     }
   t.print();

   node *res = nullptr;
   lower_bound(t.root, 5, res);
   if (res)
     std::cout << "lower_bound(5): " << res->data << std::endl;
   res = lower_bound2(t.root, 5);
   if (res)
     std::cout << "lower_bound2(5): " << res->data << std::endl;
   return 0;
}
