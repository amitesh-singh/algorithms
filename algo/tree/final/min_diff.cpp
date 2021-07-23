 #include <iostream>
#include "tree.h"

/*
 Given a binary search tree, return the minimum difference between any two nodes in the tree.

Ex: Given the following tree...
        2
       / \
      3   1
return 1.
Ex: Given the following tree...
        29
       /  \
     17   50
    /     / \
   1    42  59
return 8.
Ex: Given the following tree...
        2
         \
         100
return 98.
*/

void getMin(myds::basicnode<int> *root, int &min)
{
    if (root == nullptr) return;

    if (root->left)
        min = std::abs(root->data - root->left->data);
    if (root->right)
        min = std::min(min, std::abs(root->data - root->right->data));

    if (root->left)
        getMin(root->left, min);
    if (root->right)
        getMin(root->right, min);
}

int main()
{
    myds::tree<int, myds::basicnode<int> > tree;

    tree.insert2(2);
    tree.insert2(1);
    tree.insert2(3);

    tree.print();
    int min = INT_MAX;
    getMin(tree.root, min);

    std::cout << "min val: " << min << std::endl;

    tree.clear();

    tree.insert2(29);
    tree.insert(17);
    tree.insert2(50);
    tree.insert2(1);
    tree.insert2(42);
    tree.insert2(59);

    tree.print();

    min = INT_MAX;
    getMin(tree.root, min);

    std::cout << "min val: " << min << std::endl;


    return 0;
 }