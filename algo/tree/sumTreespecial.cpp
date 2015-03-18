#include "c_tree.h"
void dfs(Node *root,int k)
{
    int value = 0;
    if(root==NULL)return;
    else
    {
        for(int i=0;i<=1;i++)
        {
            if(i==0)
            {
                value += root->data;
                if(value==k)
                {
                    cout<<root<<" value = "<<root->data<<endl;
                    value = value-root->data;
                    return;
                }
                dfs(root->left,k);
                value = value- root->data;
            }
            else
            {
                value += root->data;
                if(value==k)
                {
                    cout<<root<<" value = "<<root->data<<endl;
                    value = value-root->data;
                    return;
                }
                dfs(root->right,k);
                value = value- root->data;
            }
        }
    }
}
void printGivenLevel(Node *root,int level)
{
    if (root == 0) return;
    if(level == 1) cout << root->data << ",";
    else if(level > 1)
    {
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}
int main()
{
    Node *root = makeBST();
    //dfs(root,47);
    printGivenLevel(root,1);

    
    return 0;
}
