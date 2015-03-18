#include "CppTree.h"
//Check whether a given Binary Tree is Complete or not
#include <queue>
struct Tree1:public Tree<int>
{
public:
	//trick - using level order traversal
bool isCompleteBT(Node<int> *root)
{
	if(root == 0)
		return true;
	bool flag = false;
	queue<Node<int> *> q;
	q.push(root);
	while(!q.empty())
	{
		Node<int> *curr = q.front();
		q.pop();
		if(curr->mLeft)
		{
			if(flag == true)
				return false;
			q.push(curr->mLeft);
		}
		else
			flag = true;
		if(curr->mRight)
		{
			if(flag == true)
				return false;
			q.push(curr->mRight);
		}
	}

	return true;

}

};
int main()
{
	Tree1 tree1;
	int arr[] = {1,2,4,5,6,8};
	tree1.mRoot = tree1.sortedArrayToBST(arr,0,5);
	tree1.levelorder1();

	cout << "iscomplete tree=" << tree1.isCompleteBT(tree1.mRoot) << endl;
	
	int i;
	cin >> i;

	return 0;

}