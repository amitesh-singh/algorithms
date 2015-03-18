#include "c_tree.h"
#include<iostream>
using namespace std;


int countHeight(Node *root,int &count)
{
    if(root ==0)
    {
        count+= 0; //count is 0
        return 0; // height is 0
    }
    count++;
    
    return max(countHeight(root->left,count),countHeight(root->right,count)) + 1;
}

int main()
{
    Node *root = makeBT();
    int i =0;
    int h = countHeight(root,i);
    cout << "h=" << h <<" c = "<< i << endl;
    cout << "count=" << countNodes(root) << endl;

    

    cleanTree(&root);
    return 0;
}
