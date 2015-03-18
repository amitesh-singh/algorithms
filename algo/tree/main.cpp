#include "CppTree.h"
#include<stack>

//sum without + 
int sum(int x,int y)
{
	int sum(0),carry(0);
	while(y!=0)
	{
		sum = x^y;
		carry = (x&y) << 1;
		x = sum;
		y = carry;
	}
	return x;
}
int main()
{
   Tree<int> tree1;
   Tree<int> tree2;
   int arr1[]=  {1,2,3,6,7};
   int arr2[] = {0,4,5,9,10};
   tree1.mRoot = tree1.sortedArrayToBST(arr1,0,4);
   tree2.mRoot = tree2.sortedArrayToBST(arr2,0,4);
   tree1.inorder();
   //tree2.inorder();
   //zig zag print 
   cout << "\nzig zag level\n";
   Node<int> *root = tree1.mRoot;
   Node<int> *head = tree1.BTtoDoublyLLZigZagOrder(root);
   int j =0;
   while(head!=0)
   {
       cout << head->mData << ",";
       head= head->mRight;
	   if(j++ == 10)
		   break;

   }
  
/*
	Tree<int> tree;
	tree.makeBT();
	cout << "Tree Code" << endl;
	tree.inorder();
	cout << "\n";
	tree.preorder();
	cout << "\n";
	tree.postorder();

	cout << "\n";
    cout << "Level Order:\n";
	tree.levelorder1();
	cout <<"\n";
	cout << "Reverse level order:\n";
	tree.reverseLevelOrder1();
	cout << "\n";
	cout << sum(10,11) << endl;

    cout << "Tree to Doubly List\n";
    Node<int> *lst = tree.treeToDoublyList(tree.mRoot);
    cout << lst->mData << endl;
    Node<int> *head = lst;
    while(head!=0)
    {
        cout << head->mData << "\n";
        head = head->mRight;
    }
*/
	int i;
	cin >> i;

	return 0;
}
