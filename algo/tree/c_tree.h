#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left,*right;
    Node(int data_):data(data_),left(0),right(0)
    {
    }
};
inline Node *newNode(int i)
{
    return new Node(i);
}
Node *makeBT()
{
    Node  *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
    return root;
}
Node *makeBST()
{
    Node  *root         = newNode(20);
    root->left                = newNode(19);
    root->left->left          = newNode(15);
    root->left->right         = newNode(21);

    root->left->right->right  = newNode(25);
    root->right               = newNode(22);
    root->right->right        = newNode(23);
    return root;
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

int countNodes(Node *root)
{
    if(root == 0)
        return 0;
    else
    {
        return (countNodes(root->left) + 1 + countNodes(root->right));
    }
}
void cleanTree(Node **root)
{
    if(*root == 0) return;
    cleanTree(&(*root)->left);
    cleanTree(&(*root)->right);
    delete *root;

}
