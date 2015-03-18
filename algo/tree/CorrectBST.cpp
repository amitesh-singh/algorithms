//what if two nodes on a BST is swapped how will you correct it in O(n)


#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    Node(int data_):data(data_),left(0),right(0){}
};


void CorrectBSTUtil(Node *root,Node *&first,Node *&middle,Node *&last,Node *&prev)
{
    if(root)
    {
    CorrectBSTUtil(root->left,first,middle,last,prev);

    if(prev && root->data < prev->data)
    {
        if(!first)
        {
            first = prev;
            middle = root;
        }
        else
            last = root;

    }
    prev = root;

    CorrectBSTUtil(root->right,first,middle,last,prev);
    }
}
void CorrectBST(Node *root)
{
    Node *first(0),*middle(0),*last(0),*prev(0);

    CorrectBSTUtil(root,first,middle,last,prev);
    cout << "first:" << first->data << "\n";
    cout << "middle:" << middle->data << "\n";
    cout << "last:" << last->data << "\n";
    if(first && last)
    {
        swap(first->data,last->data);
    }
    else if(first && middle)
    {
        swap(first->data,middle->data);
    }
    
}

void inorder(Node *root)
{
    if(root==0)
        return;
    inorder(root->left);
    if(root)
        cout << root->data << ",";
    inorder(root->right);
}
int main()
{
    Node *root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(12);



    inorder(root);
    cout << endl;
    CorrectBST(root);
    inorder(root);
    cout << endl;

    return 0;
}
