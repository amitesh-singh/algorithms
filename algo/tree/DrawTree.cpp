#include "CppTree.h"
#include <map>
#include <queue>
#include <string>
#include<iomanip>


template<class T>
struct DrawTree:public Tree<T>
{
	map<Node<T> *,int> mStorage;
	static const int space = 20;
	//calculate horizontal distance; start from 0 (root)
	void _calculateHD(Node<T> *root,int val)
	{
		if(root == 0) return;
		_calculateHD(root->mLeft,val -1);
		mStorage[root] = val;
		_calculateHD(root->mRight,val+1);
	}
	void populateHD()
	{
		int val = 0;
		_calculateHD(mRoot,val);
	}
	string returnSpace(int s)
	{
		std::string s1(" ");
		string ret;
		for(int i =0;i<s;i++)
			ret+=s1;
		return ret;
	}
	void _printNode(Node<T> *curr,Node<T> *next,Node<T> *prev)
	{
		int hd_curr =0,hd_prev = 0,hd_next = 0;
		if(prev)
			hd_prev = mStorage[prev];
		if(


		
	}
	//Level order printing using 2 queues 
	// - special case
	void _levelOrder(Node<T> *root,string &str)
	{
		if(root == 0) return;

		queue<Node<T> *> currLevel,nextLevel;
		currLevel.push(root);
		cout << "\nTREE DRAW\n";
		cout << returnSpace(space);
		Node<T> *next = 0;
		while(!currLevel.empty())
		{
			Node<T> *curr = currLevel.front();
			currLevel.pop();
			if(!currLevel.empty())
				next = currLevel.front();
			if(curr)
			{
				_printNode(curr,next);
				if(curr->mLeft)
					nextLevel.push(curr->mLeft);
				if(curr->mRight)
					nextLevel.push(curr->mRight);
				
			}
			if(currLevel.empty())
			{
				cout << "\n";
				swap(currLevel,nextLevel);
				int s = space;
				if(!currLevel.empty())
					s+= mStorage[currLevel.front()];
				cout << returnSpace(s);
			}
		}

	}
	void drawTree()
	{
		populateHD();
		string str;
		_levelOrder(mRoot,str);
		
	}
	void _inorder123(Node<T> *root)
	{
		if(root == 0)
			return;
		_inorder123(root->mLeft);
		cout << root->mData << ":" << mStorage[root] << endl;
		_inorder123(root->mRight);
	}
	void printHD()
	{
		_inorder123(mRoot);
	}

};
int main()
{
	DrawTree<int> dt;
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	dt.mRoot = dt.sortedArrayToBST(arr,0,9);
	dt.drawTree();
	cout << endl;
	dt.printHD();
	system("pause");


	return 0;
}