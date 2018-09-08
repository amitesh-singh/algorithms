#include <iostream>

using namespace std;

struct node
{
   int key;
   node *left, *right;

   node(int k = 0, node *l = 0, node *r = 0): key(k), left(l), right(r)
   {
   }
};

void insert(node *&root, int k)
{
    if (root == 0)
    {
        node *newnode = new node(k);
        root = newnode;
        return;
    }

    if (k < root->key)
        insert(root->left, k);
    else if (k > root->key)
        insert(root->right, k);
    else
      ; //duplicate, don't do anything
}

node *search(node *root, int k)
{
    if (root == 0 || k == root->key)
        return root;
    
    if (k < root->key)
        return search(root->left, k);
    else
        return search(root->right, k);
}


void inorder(node *root)
{
    if (root == 0) return;
    inorder(root->left);
    cout << root->key << endl;
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == 0) return;
    cout << root->key << endl;
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == 0) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << endl;
}

node *findMin(node *root)
{
    if (root && root->left == 0) return root;
    else
        return findMin(root->left);
}

node *findMax(node *root)
{
    if (root && root->right == 0) return root;
    else
        return findMax(root->right);
}

int main()
{
   int T;
   int N;
   int number;

   node *root = 0;

   freopen("input.txt", "r", stdin);
   cin >> T;
   for (register unsigned int t = 1; t <= T; ++t)
   {
       cin >> N;
       root = 0;
       for (register unsigned int n = 1; n <= N; ++n)
       {
           cin >> number;
           insert(root, number);
       }

       cout << "finding 11: " << search(root, 11)->key << endl;
       cout << "inorder: ";
       inorder(root);
       
       cout << " preorder: ";
       preorder(root);

       cout << "postorder: ";
       postorder(root);

       cout << "min is: " << findMin(root)->key << endl;
       
       cout << "max is: " << findMax(root)->key << endl;
   }

   return 0;
}
