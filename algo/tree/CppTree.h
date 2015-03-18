#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;


template<class T>
struct Node
{
    T mData;
    Node<T> *mLeft;
    Node<T> *mRight;

    Node(T _data):mData(_data),mLeft(0),mRight(0){}

};

template<class T>
class Tree
{
    public:
        Node<T> *zigzagLevelSinglyLinkedList(Node<T> *root)
        {
            if(root == 0)
                return 0;
            queue<Node<T> *> q;
            Node<T> *first = root;
            q.push(root);
            while(!q.empty())
            {
                Node<T> *curr = q.front();
                q.pop();
                if(curr->mLeft)
                    q.push(curr->mLeft);
                if(curr->mRight)
                    q.push(curr->mRight);
                curr->mRight = q.front();

            }
            return first;
        }
        Node<T> *BTtoDoublyLLZigZagOrder(Node<T> *root)
        {
            if(root == 0)
                return 0;
            queue<Node<T> *> q;
            q.push(root);
            Node<T> *head = root;
            Node<T> *prev = 0,*curr = 0;
            while(!q.empty())
            {
                curr = q.front();
                q.pop();
                if(curr->mLeft)
                    q.push(curr->mLeft);
                if(curr->mRight)
                    q.push(curr->mRight);
                curr->mRight = q.front();
                curr->mLeft = prev;
                prev = curr;
            }
            return head;

        }
        Node<T> *BTtoCircularDoublyLLZigZagOrder(Node<T> *root)
        {
            if(root == 0)
                return 0;
            queue<Node<T> *> q;
            q.push(root);
            Node<T> *head = root;
            Node<T> *prev = 0,*curr = 0;
            while(!q.empty())
            {
                curr = q.front();
                q.pop();
                if(curr->mLeft)
                    q.push(curr->mLeft);
                if(curr->mRight)
                    q.push(curr->mRight);
                curr->mRight = q.front();
                curr->mLeft = prev;
                prev = curr;
            }
            //connect the head and last node
            head->mLeft = curr;
            curr->mRight = head;
            return head;

        }

        Node<T> *mRoot;
        void _inorder(Node<T> *root)
        {
            if(root == 0)
                return;
            _inorder(root->mLeft);
            cout << root->mData << ",";
            _inorder(root->mRight);
        }
        void _postorder(Node<T> *root)
        {
            if(root == 0)
                return;
            _inorder(root->mLeft);
            _inorder(root->mRight);
            cout << root->mData << ",";
        }
        void _preorder(Node<T> *root)
        {
            if(root == 0)
                return;
            cout << root->mData << ",";
            _inorder(root->mLeft);
            _inorder(root->mRight);
        }
        void _cleanTree(Node<T> *root)
        {
            if(root == 0)
                return;
            _cleanTree(root->mLeft);
            _cleanTree(root->mRight);
            if(root!=0)
            {
                cout << "cleaning - " << root << endl;
                delete root;
            }
        }

        /*
           1
           2     3
           4  5   6  7

           print the tree in following order
           1,3,2,7,6,5,4
         */
        void _reverseLevelOrder1(Node<T> *root)
        {
            if(root ==0) return;
            queue<Node<T> *> q;
            q.push(root);
            while(q.empty() == false)
            {
                Node<T> *temp = q.front();
                cout << temp->mData << ",";
                q.pop();
                if(temp->mRight)
                    q.push(temp->mRight);
                if(temp->mLeft)
                    q.push(temp->mLeft);
            }

        }
        void reverseLevelOrder1()
        {
            _reverseLevelOrder1(mRoot);
        }

        void _levelorder1(Node<T> *root)
        {
            if(root ==0) return;
            queue<Node<T> *> q;
            q.push(root);
            while(!q.empty())
            {
                Node<T> *temp = q.front();
                cout << temp->mData <<",";
                q.pop();
                if(temp->mLeft != 0)
                    q.push(temp->mLeft);
                if(temp->mRight != 0)
                    q.push(temp->mRight);
            }
        }
        void joinList(Node<T> *a,Node<T> *b)
        {
            a->mRight = b;
            b->mLeft = a;
        }
        Node<T> *addTwoLists(Node<T> *a,Node<T> *b)
        {
            if(a == 0) return b;
            if(b == 0) return a;
            Node<T> *aLeft,*bLeft;
            aLeft = a->mLeft;
            bLeft  = b->mLeft;
            joinList(aLeft,b);
            joinList(bLeft,a);

            return a;

        }
        void _treeToDoublyList(Node<T> *root,Node<T> *&prev,Node<T> *&head)
        {
            if(root == 0)
                return;
            _treeToDoublyList(root->mLeft,prev,head);
            root->mLeft = prev;
            if(prev)
                prev->mRight = root;
            else
                head = root;


            Node<T> *right = root->mRight;
            head->mLeft = root;
            root->mRight = head;
            prev = root;

            _treeToDoublyList(root->mRight,prev,head);
        }
        Node<T> *treeToDoublyList(Node<T> *root)
        {
            Node<T> *prev = 0;
            Node<T> *head = 0;
            _treeToDoublyList(root,prev,head);
            return head;
        }

        ~Tree()
        {
            //_cleanTree(mRoot);
        }

        void inorder()
        {
            _inorder(mRoot);
        }
        void postorder()
        {
            _postorder(mRoot);
        }
        void preorder()
        {
            _preorder(mRoot);
        }
        void levelorder1()
        {
            _levelorder1(mRoot);
        }
        void _fillLevelOrderTree(Node<T> *root,T &cont,int &index)
        {   

        }
        //dummy function to build a tree for testing purpose
        void makeBT()
        {
            //_fillLevelOrderTree(mRoot,cont,index);
            mRoot = new Node<int>(1);
            mRoot->mLeft = new Node<int>(2);
            mRoot->mRight = new Node<int>(3);
            mRoot->mLeft->mLeft = new Node<int>(4);
            mRoot->mLeft->mRight = new Node<int>(5);
            mRoot->mRight->mLeft = new Node<int>(6);
            mRoot->mRight->mRight = new Node<int>(7);
        }
        Node<T> *sortedArrayToBST(T arr[],int start,int end)
        {
            if(start > end)
                return 0;
            int mid = (start + end)/2;
            Node<T> *root = new Node<T>(arr[mid]);
            root->mLeft = sortedArrayToBST(arr,start,mid-1);
            root->mRight = sortedArrayToBST(arr,mid+1,end);
            cout << root << endl;
            return root;
        }

};



















