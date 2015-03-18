#include "c_tree.h"

void displayPath(Node *root,int key)
{
    if(root)
    {
        if(key == root->data)
        {
            cout << root->data << ",";
        }
        else if(key < root->data)
        {
            cout << root->data << ",";
            displayPath(root->left,key);
        }
        else
        {
            cout << root->data << ",";
            displayPath(root->right,key);
        }
        
    }
}
//bottom to up
void displayPath1(Node *root,int key)
{
    if(root)
    {
        if(key == root->data)
        {
            cout << root->data << ",";
        }
        else if(key < root->data)
        {
            displayPath1(root->left,key);
            cout << root->data << ",";
        }
        else
        {
            displayPath1(root->right,key);
            cout << root->data << ",";
        }
    }
}
int main()
{
    Node *root = makeBST();
    displayPath(root,25);
    cout << endl;
    displayPath1(root,25);


    return 0;
}
