#include "CppTree.h"
#include<map>
#include<iterator>
#include <algorithm>

struct Tree2:public Tree<int>
{
	map<Node<int> *,int> hashHD;
	void calculateHD(Node<int> *root,int val,map<Node<int> *,int> &hashHD)
	{
		if(root == 0)
			return;
		calculateHD(root->mLeft,val-1,hashHD);
		hashHD[root] = val;
		calculateHD(root->mRight,val+1,hashHD);
	}
	//override
	void _inorder(Node<int> *root)
	{
		if(root == 0) return;
		_inorder(root->mLeft);
		int i = hashHD[root];
		cout << root->mData << ":" << i << endl;
		_inorder(root->mRight);
	}
	void inorder()
	{
		_inorder(mRoot);
	}
};
int main()
{
	Tree2 tree2;
	int arr[] = {1,2,3,4};
	tree2.mRoot = tree2.sortedArrayToBST(arr,0,3);
	tree2.calculateHD(tree2.mRoot,0,tree2.hashHD);
	//std::copy(tree2.hashHD.begin(),tree2.hashHD.end(),std::ostream_iterator<map<int,int> >(cout,","));
	tree2.inorder();	
	system("pause");
	return 0;
}