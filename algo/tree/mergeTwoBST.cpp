#include "CppTree.h"
#include<stack>
struct Tree1:public Tree<int>
{
    void sortedPrint(Node<int> *root1,Node<int> *root2)
    {
        if(root1 == 0)
        {
            _inorder(root1);
            return;
        }
        if(root2 == 0)
        {
            _inorder(root2);
            return;
        }
        stack<Node<int> *> s1,s2;
        Node<int> *curr1,*curr2;
        curr1 = root1;
        curr2 = root2;
        Node<int> *one,*two;
        while(curr1 || curr2 || !s1.empty() || !s2.empty())
        {
            while(curr1)
            {
                s1.push(curr1);
                curr1 = curr1->mLeft;
            }
            while(curr2)
            {
                s2.push(curr2);
                curr2 = curr2->mLeft;
            }
            if(!s1.empty() && !s2.empty())
            {
                one = s1.top();
                two = s2.top();
                if(one->mData > two->mData)
                {
                    cout << two->mData << ",";
                    s2.pop();
                    curr2 = two->mRight;
                }
                else
                {
                    cout << one->mData << ",";
                    s1.pop();
                    curr1 = one->mRight;
                }
            }
            else if(!s1.empty() && s2.empty())
            {
                one = s1.top();
                cout << one->mData << ",";
                s1.pop();
                curr1 = one->mRight;
            }
            else if(!s2.empty() && s1.empty())
            {
                two = s2.top();
                cout << two->mData << ",";
                s2.pop();
                curr2 = two->mRight;
            }

        }
    }
};
int main()
{
    cout << __func__ << endl;
    Tree1 tree;
    Tree<int> tree1;
    Tree<int> tree2;
    int arr1[] = {1,2,3,4};
    int arr2[] = {0,5,6,7};
    tree1.mRoot = tree1.sortedArrayToBST(arr1,0,3);
    tree2.mRoot = tree2.sortedArrayToBST(arr2,0,3);
    cout << "Tree1\n";
    tree1.inorder();
    cout << "\n";
    cout << "Tree2\n";
    tree2.inorder();
    cout << "\n";


    tree.sortedPrint(tree1.mRoot,tree2.mRoot);
    cout << "\n";

    tree1._cleanTree(tree1.mRoot);
    tree2._cleanTree(tree2.mRoot);
    return 0;
}
