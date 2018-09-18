#include <iostream>

using namespace std;

struct node
{
    int key;
    int height;
    node *left, *right;

    node(int k = 0, node *l = 0, node *r = 0): key(k), left(l), right(r), height(0)
   {
   }
};

int height(node *root)
{
   return root == 0 ? -1 : root->height;
}

static const int ALLOW_IMBLANCE = 1;

void rotateWithLeftChild(node *&k2)
{
   node *k1 = k2->left;
   k2->left = k1->right;
   k1->right = k2;

   k2->height = max(height(k2->left), height(k2->right)) + 1;
   k1->height = max(height(k1->left), k2->height) + 1;

   k2 = k1;
}

void rotateWithRightChild(node *&k2)
{
   node *k1 = k2->right;
   k2->right = k1->left;
   k1->left = k2;

   k2->height = max(height(k2->left), height(k2->right)) + 1;
   k1->height = max(height(k1->right), k2->height) + 1;

   k2 = k1;
}

void doubleRotateWithLeftChild(node *&k3)
{
   rotateWithRightChild(k3->left);
   rotateWithLeftChild(k3);
}

void doubleRotateWithRightChild(node *&k3)
{
   rotateWithLeftChild(k3->right);
   rotateWithRightChild(k3);
}

void balance(node *&root)
{
   if (!root) return;

   if (height(root->left) - height(root->right) > ALLOW_IMBLANCE)
     {
        if (height(root->left->left) >= height(root->left->right))
          rotateWithLeftChild(root);
        else
          doubleRotateWithLeftChild(root);
     }
   else if (height(root->right) - height(root->left) > ALLOW_IMBLANCE)
     {
        if (height(root->right->right) >= height(root->right->left))
          rotateWithRightChild(root);
        else
          doubleRotateWithRightChild(root);
     }

   root->height = max(height(root->left), height(root->right)) + 1;
}

void insert(node *&root, int k)
{
   if (root == 0)
     root = new node(k), cout << "inserted " << k << endl;
   else if (k < root->key)
     insert(root->left, k);
   else if (k > root->key)
     insert(root->right, k);
   else
     ; //no duplicates; will implement it later

   balance(root);
}

void preorder(node *root)
{
   if (!root) return;
   cout << root->key;
   if (root->left)
     cout << " L(" << root->left->key << ")";
   if (root->right)
     cout << " R(" << root->right->key << ")";
   cout << endl;

   preorder(root->left);
   preorder(root->right);
}

void deleteTree(node *&root)
{
   if (!root) return;
   deleteTree(root->left);
   deleteTree(root->right);

   delete root;
   root = 0;
}

node *findMin(node *root)
{
   if (root == 0) return 0;
   else if (root->left == 0) return root;
   else return findMin(root->left);
}

void remove(node *&root, int k)
{
   if (root == 0) return;
   else if (k < root->key)
     remove(root->left, k);
   else if (k > root->key)
     remove(root->right, k);
   else if (root->left && root->right)
     {
        root->key = findMin(root->right)->key;
        remove(root->right, root->key);
     }
   else
     {
        node *tmp = root;
        if (root->left) root = root->left;
        else root = root->right;
        delete tmp;
     }

   balance(root);
}

int main()
{
   node *root = 0;
   insert(root, 90);
   insert(root, 9);
   insert(root, 89);
   insert(root, 56);

   preorder(root);

   cout << "Deleted 9\n";
   remove(root, 9);

   preorder(root);

   deleteTree(root);

   return 0;
}
