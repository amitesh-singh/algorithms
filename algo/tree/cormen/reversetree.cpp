//we store items in opposite order
// bigger items on left side and smaller items in right side.

#include <iostream>

using namespace std;

struct node
{
    node *left, *right;
    int key; //distance.
    node(int k):left(0), right(0), key(k)
    {
    }
};

void insert(node *&root, int key)
{
    if (root == 0)
    {
        root = new node(key);
        return;
    }

    if (key > root->key)
        insert(root->left, key);
    else if (key < root->key)
        insert(root->right, key);
    else
        ; //ignore duplicate items
}

void inorder(node *root)
{
    if (root == 0) return;
    inorder(root->left);
    cout << "key:" << root->key << endl;
    inorder(root->right);
}

node *findLeftMost(node *root)
{
    if (root && root->left == 0)
        return root;
    else
        return findLeftMost(root->left);
}

node *findRightMost(node *root)
{
    if (root && root->right == 0)
        return root;
    else
        return findRightMost(root->right);
}

void remove(node *&root, int k)
{
    if (root == 0) return;
    if (k > root->key)
        remove(root->left, k);
    else if (k < root->key)
        remove(root->right, k);
    else if (root->left && root->right)
    {
        node *n = findRightMost(root->left);
        root->key = n->key;
        remove(root->left, root->key);
    }
    else
    {
        node *tmp = root;
        if (root->left)
            root = root->left;
        else
            root = root->right;
        delete tmp;
    }
}

void inorderOpposite(node *root)
{
    if (root == 0)
        return;
    inorderOpposite(root->right);
    cout << root->key << endl;
    inorderOpposite(root->left);
}

int main()
{
    node *root = 0;

    insert(root, 10);
    insert(root, 11);
    insert(root, 0);
    insert(root, 13);
    insert(root, 1);
    insert(root, 2);
    insert(root, 12);
    insert(root, 8);
    insert(root, 100);

    inorder(root);
    cout << "decending order? " << endl;
    inorderOpposite(root);
    cout << "deleting node(10) \n";
    remove(root, 10);
    inorder(root);
    return 0;
}