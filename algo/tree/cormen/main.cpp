#include <iostream>

using namespace std;

struct node
{
   int key;
   node *left, *right;
   node *parent;
   node(int k = 0, node *l = 0, node *r = 0): key(k), left(l), right(r)
   {
       parent = 0;
   }
};

void insert(node *&root, int k, node *p = 0)
{
    if (root == 0)
    {
        node *newnode = new node(k);
        newnode->parent = p;
        root = newnode;

        return;
    }

    if (k < root->key)
        insert(root->left, k, root);
    else if (k > root->key)
        insert(root->right, k, root);
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

node *iterativeSearch(node *root, int k)
{
    while (root != 0 && k != root->key)
    {
        if (k < root->key)
            root = root->left;
        else
            root = root->right;
    }

    return root;
}

//it gives the output in ascending order
void inorder(node *root)
{
    if (root == 0) return;
    inorder(root->left);
    cout << root->key << endl;
    inorder(root->right);
}
//it gives output in descending order
void inorderDescendingOrder(node *root)
{
    if (root == 0) return;
    inorderDescendingOrder(root->right);
    cout << root->key << endl;
    inorderDescendingOrder(root->left);
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

node *successor(node *root)
{
    if (root == 0) return 0;
    if (root->right)
        return findMin(root->right);
    node *p = root->parent;
    while (p && root == p->right)
    {
        root = p;
        p = root->parent;
    }
    
    return p;
}

void remove(node *&root, int k)
{
    if (root == 0) return;
    if (k < root->key)
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
        if (root->left)
            root = root->left;
        else
            root = root->right;
        
        delete tmp;
    }
}

void deleteTree(node *&root)
{
    if (root == 0) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = 0;
}

int height(node *root)
{
   if (root == 0) return 0;
   return std::max(height(root->left), height(root->right)) + 1;
}

//this finds the nearest number to input number k.
node *findClosestNode(node *root, int k)
{
    if (root == 0) return nullptr;
    else if (k == root->key)
    {
        return root;
    }
    else if (k < root->key)
    {
        if (!root->left) return root;
        // find the closest one in left subtree
        node *p = findClosestNode(root->left, k);
        return (abs(root->key - k) < abs(p->key - k) ? root : p);
    }
    else if (k > root->key)
    {
        if (!root->right) return root;
        //find the closest one in right subtree
        node *p = findClosestNode(root->right, k);
        return (abs(root->key - k) < abs(p->key) - k ? root : p);
    }

    return nullptr;
}

template <class T>
void printBT(const std::string& prefix, const T* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->key << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

template <class T>
void printBT(const T *root)
{
   printBT("", root, false);
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

       //cout << "finding 11: " << search(root, 11)->key << endl;
       //cout << "finding 11 using iterativeSearch: " << iterativeSearch(root, 11)->key << endl;
       cout << "inorder: ";
       inorder(root);
       
       cout << " preorder: ";
       preorder(root);

       cout << "postorder: ";
       postorder(root);
       
       cout << "inorder: descending order: ";
       inorderDescendingOrder(root);

       cout << "min is: " << findMin(root)->key << endl;
       
       cout << "max is: " << findMax(root)->key << endl;
       cout << "successor(9) is: " << successor(search(root, 9))->key << endl;
       cout << "height=" << height(root) << "\n";
       cout << "delete 9: " << endl;
       printBT(root);
       remove(root, 9);
       printBT(root);
       
       cout << "closest number to 10 is " << findClosestNode(root, 10)->key << endl;
       
       inorder(root);
       cout << "clean the root: ";
       deleteTree(root);
       cout << "root address is : " << root << endl;

   }

   return 0;
}
