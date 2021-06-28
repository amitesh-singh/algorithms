#include "tree.h"
#include <iostream>
#include <ctime>
#include <queue>
#include <unordered_map>
#include <stack>

using node = myds::basicnode<int>;
node *clone_tree_bfs(node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    std::queue<node *> q;
    std::unordered_map<node *, node *> hash;
    q.push(root);
    node *copyroot = new node(root->data);
    hash[root] = copyroot;

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; ++i)
        {
            node *curr = q.front();
            q.pop();

            if (curr->left)
            {
                if (hash.find(curr->left) == hash.end())
                {
                    hash[curr->left] = new node(curr->left->data);
                    q.push(curr->left);
                }
                hash[curr]->left = hash[curr->left];
            }
            if (curr->right)
            {
                if (hash.find(curr->right) == hash.end())
                {
                    hash[curr->right] = new node(curr->right->data);
                    q.push(curr->right);
                }
                hash[curr]->right = hash[curr->right];
            }
        }
    }

    return copyroot;    
}

void inorder(node *root)
{
    if (root == nullptr) return;
    if (root->left) inorder(root->left);
    std::cout << root->data << "->";
    if (root->right) inorder(root->right);
}

node *clone_tree_dfs(node *root)
{
    if (root == nullptr) return nullptr;
    std::unordered_map<node *, node *> hash;
    node *copyroot = nullptr;
    std::stack<node *> s;
    s.push(root);
    
    copyroot = new node(root->data);
    hash[root] = copyroot;

    while (!s.empty())
    {
        //preorder
        node *curr = s.top();
        s.pop();

        if (curr->left)
        {
            if (hash.find(curr->left) == hash.end())
            {
                hash[curr->left] = new node(curr->left->data);
                s.push(curr->left);
            }
            hash[curr]->left = hash[curr->left];
        }
        if (curr->right)
        {
             if (hash.find(curr->right) == hash.end())
            {
                hash[curr->right] = new node(curr->right->data);
                s.push(curr->right);
            }
            hash[curr]->right = hash[curr->right];
        }
    }

    return copyroot;
}
int main()
{
    std::srand(std::time(nullptr));

    myds::tree<int, myds::basicnode<int> > t;
     for (int i = 0; i < 25; ++i)
     {
        t.insert(rand() % 131);
     }
     t.print();
     myds::basicnode<int> *root2 = nullptr;
     root2 = clone_tree_bfs(t.root);

    inorder(root2);
    std::cout << "\nDFS Copy: \n";
    root2 = clone_tree_dfs(t.root);
    inorder(root2);

    return 0;
}