//check if the given tree is a bst or not.
//common mistake is to compare root->val with left->val and right-val

#include "tree.h"
#include <vector>

using node = myds::basicnode<int>;
void inorder(node *root, std::vector<int> &v)
{
    if (root == nullptr) return;
    if (root->left)
        inorder(root->left, v);
    v.push_back(root->data);
    if (root->right)
        inorder(root->right, v);
}
bool isbst(node *root)
{
    if (root == nullptr) return true;
    std::vector<int> v;
    //traverse in inorder
    inorder(root, v);

    //check if the array is sorted or not.
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i-1] >= v[i])
            return false;
    }

    return true;
}

//effecient and simpler
bool isbst3(node *root, node *min, node *max)
{
    if (root == nullptr) return true;
    if (min && min->data >= root->data) return false;
    if (max && max->data <= root->data) return false;

    return isbst3(root->left, min, root) && isbst3(root->right, root, max);
}

int maxval(node *root)
{
      node *p = root;
    while (p->right)
        p = p->right;

    return p->data;
}

int minval(node *root)
{
    node *p = root;
    while (p->left)
    {
        p = p->left;
    }

    return p->data;
}
//using min at left subtree and max at right subtree
bool isbst2(node *root)
{
    if (root == nullptr) return true;
    if ((root->left &&root->data <= maxval(root->left)) || (root->right && root->data >= minval(root->right)))
     return false;
    
    return isbst2(root->left) && isbst2(root->right);
}

int main()
{
   myds::tree<int, myds::basicnode<int>> t = {20, 21, 22};
   t.insert(10);
   t.insert(11);
   t.insert(12);

   std::cout << "isbst: " << isbst(t.root) << std::endl;
   std::cout << "isbst2: " << isbst2(t.root) << std::endl;
 
   std::cout << "isbst3: " << isbst3(t.root, nullptr, nullptr) << std::endl;
    return 0;
}
