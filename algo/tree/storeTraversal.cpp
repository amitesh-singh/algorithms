#include<iostream>
#include "c_tree.h"

using namespace std;
void storeInorder(Node *root,int inord[],int &index)
{
    if(root == 0)
        return;
    storeInorder(root->left,inord,index);
    inord[index++] = root->data;
    storeInorder(root->right,inord,index);
}
void storePreorder(Node *root,int pre[],int &index)
{
    if(root == 0)
        return;
    pre[index++] = root->data;
    storePreorder(root->left,pre,index);
    storePreorder(root->right,pre,index);
}

void storePostOrder(Node *root,int post[],int &index)
{
    if(root == 0)
        return;
     storePostOrder(root->left,post,index);
     storePostOrder(root->right,post,index);

     post[index++] = root->data;
}

int main()
{
    Node *root = makeBST();
    inorder(root);
    int n = countNodes(root);
    int index = 0;
    int *inord = new int[n];
    storeInorder(root,inord,index);
    cout << "Inorder:";
    for(int i =0;i<n;++i)
    {
        cout << inord[i] << ",";
    }
    cout << "\n";
    int *pre = new int[n];
    index = 0;
    storePreorder(root,pre,index);
    cout << "Preorder:";
    for(int i =0;i<n;++i)
    {
        cout << pre[i] << ",";
    }
    cout << "\n";
    cout << "PostOrder:";
    int *post = new int;
    index = 0;
    storePostOrder(root,post,index);
    
    for(int i =0;i<n;++i)
    {
        cout << post[i] << ",";
    }
    cout << "\n";
    delete [] post;
    delete [] inord;
    delete [] pre;
    return 0;
}
