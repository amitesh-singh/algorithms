#include "CppTree.h"


bool isMirror(Node<int> *root1,Node<int> *root2)
{

   if(root1 == 0 && root2 == 0)
     return true;
   else if(root1 == 0 && root2 != 0)
     return false;
   else if(root1 != 0 && root2 == 0)
     return false;

   else if(root1 != 0 && root2 !=0)
     return ((root1->mData == root2->mData)&& isMirror(root1->mLeft,root2->mRight) && isMirror(root1->mRight,root2->mLeft));
   else
     return false; 

}

bool isSameTree(Node<int> *root1,Node<int> *root2)
{
   if(root1 == 0 && root2 == 0)
     return true;
   else if(root1 != 0 && root2 == 0)
     return false;
   else if(root1 == 0 && root2!= 0)
     return false;
   else if(root1 != 0 && root2!=0)
     return (root1->mData == root2->mData && isSameTree(root1->mLeft,root2->mLeft) && isSameTree(root1->mRight,root2->mRight));
   else
     return false;
}
//PS: root1 > root2
bool isSubTree(Node<int> *root1,Node<int> *root2)
{
   if(root1 == 0 && root2 == 0)
     return true;
   else if(root1 != 0 && root2 == 0)
     return false;
   else if(root1 ==0 && root2 != 0)
     return false;
   else if(root1 != 0 && root2!=0)
     {
        if(root1->mData == root2->mData)
          return isSubTree(root1->mLeft,root2->mLeft) && isSubTree(root1->mRight,root2->mRight);
        else
          return isSubTree(root1->mLeft,root2) && isSubTree(root1->mRight,root2);
     }
   else 
     return false;
}

int main()
{
   Tree<int> tree1;
   int arr[] = {1,2,4};
   tree1.mRoot = tree1.sortedArrayToBST(arr,0,2);
   tree1.inorder();
   cout << "\n";
   tree1.preorder();

   cout << "\n";
   Tree<int> tree2;
   int arr2[] = {4,2,1};
   tree2.mRoot = tree2.sortedArrayToBST(arr2,0,2);
   tree2.inorder();
   cout << "\n";
   tree2.preorder();

   cout << "\n";
   cout << isMirror(tree1.mRoot,tree2.mRoot);
   system("pause");


   return 0;
}


