#include "tree.h"
#include <iostream>
#include <ctime>

using node = myds::basicnode<int>;

int height(node *root)
{
    if (root == nullptr) return 0;
    return std::max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(node *root)
{
    if (root == nullptr) return true;
    int left_height = height(root->left);
    int right_height = height(root->right);

    if (std::abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
}

int main()
{
    std::srand(std::time(nullptr));
    myds::tree<int, myds::basicnode<int> > t;
    for (int i = 0; i < 5; ++i)
    {
        t.insert(std::rand() % 101);
    }    

    t.print();

    std::cout << "is balanced: " << isBalanced(t.root) << std::endl;   

    return 0;
}