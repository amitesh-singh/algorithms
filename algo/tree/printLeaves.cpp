#include<iostream>
#include<vector>

#include "c_tree.h"

using namespace std;


void printLeaves(Node *root)
{
    if(root)
    {
        printLeaves(root->left);
        if(!(root->left) && !(root->right))
            cout << root->data << ",";
        printLeaves(root->right);
    }
}
void inorder(Node *root)
{
   if(root)
   {
       inorder(root->left);
       cout << root->data << ",";
       inorder(root->right);
   }
}

int main()
{
    Node *root = makeBT();
    inorder(root);

    cout << "\nleaves only\n";
    printLeaves(root);


    return 0;
}

