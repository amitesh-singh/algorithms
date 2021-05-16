#include <iostream>
#include "tree.h"
#include <vector>
#include <algorithm>


struct mytree: public myds::tree<int, myds::basicnode<int> >
{
    using node = myds::basicnode<int>;
    private:

    public:

    //find a subtree in a tree
    bool findsubtree(mytree &t)
    {
       //first find the subtree's root node position in the tree
       node *root2 = t.find(t.root->data);
       if (!root2) return false;

       bool isequal =__isequal(root2, t.root);

       return isequal;
    }

    void inorder2(node *p, std::vector<int> &v)
      {
         if (p == nullptr) return;
         inorder2(p->left, v);
         v.push_back(p->data);
         inorder2(p->right, v);
      }
    void postorder2(node *p, std::vector<int> &v)
      {
         if (p == nullptr) return;
         postorder2(p->left, v);
         postorder2(p->right, v);
         v.push_back(p->data);
      }
    //better and easier code 
    // a tree is unique if inorder, and post order traversal are given

    //do inorder and postorder traversal on both and compare the path
    bool findsubtree2(mytree &t)
      {
         //
         std::vector<int> v1, v2;
         inorder2(root, v1);
         inorder2(t.root, v2);

         std::cout << "inorder: \n";
         for (auto &x: v1)
           std::cout << x << ", ";
         std::cout << "\n";
         for (auto &x: v2)
           std::cout << x << ", ";
         std::cout << "\n";

         //find if v1 == v2(subset)
         auto it1 = std::search(begin(v1), end(v1), begin(v2), end(v2));
         if (it1 == end(v1))
           return false;
         v1.clear();
         v2.clear();

         postorder2(root, v1);
         postorder2(t.root, v2);
         std::cout << "postorder : \n";
         for (auto &x: v1)
           std::cout << x << ", ";
         std::cout << "\n";
         for (auto &x: v2)
           std::cout << x << ", ";
         std::cout << "\n";
         //find if v1 == v2(subset)
         it1 = std::search(begin(v1), end(v1), begin(v2), end(v2));
         if (it1 == end(v1))
           return false;
         v1.clear();
         v2.clear();

         return true;
      }
};

#include <ctime>

int main()
{
    std::srand(std::time(nullptr));
    mytree mt;
    mt.insert(14);
    mt.insert(4);
    mt.insert(10);
    mt.insert(0);
    mt.insert(11);
    mt.insert(12);

    mt.print();

    mytree mt2;
    mt2.insert(10);
    mt2.insert(11);

    mt2.print();

    std::cout << "is subtree: " << mt.findsubtree(mt2) << std::endl;
    std::cout << "is subtree: " << mt.findsubtree2(mt2) << std::endl;


    return 0;
}
