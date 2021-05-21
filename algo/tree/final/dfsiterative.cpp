#include <iostream>
#include "tree.h"
#include <stack>

using node = myds::basicnode<int>;

//preorder using stack
void dfs(node *curr)
{
    std::stack<node *> s;
    s.push(curr);

    while (!s.empty())
    {
        node *p = s.top();
        s.pop();
        std::cout << p->data << ", ";
        if (p->right) s.push(p->right);
        if (p->left) s.push(p->left);
    }

    std::cout << std::endl;
}

//postorder using stack
void dfs_post(node *curr)
{
    std::stack<node *> s1, s2;
    s1.push(curr);
    while (!s1.empty())
    {
        node *p = s1.top();
        s1.pop();
        s2.push(p);
        if (p->left) s1.push(p->left);
        if (p->right) s1.push(p->right);
    }

    while (!s2.empty())
    {
        node *p = s2.top();
        s2.pop();
        std::cout << p->data << ", ";
    }

    std::cout << '\n';
}

void dfs_inorder(node *curr)
{
    std::stack<node *> s;

    while (!s.empty() || curr)
    {
        if (curr)
        {
            s.push(curr);
            curr = curr->left;   
        }
        else
        {
            node *p = s.top();
            s.pop();
            std::cout << p->data << " ,";
            curr = p->right;
        }
    }
    std::cout << "\n";
}

int main()
{
    myds::tree<int, myds::basicnode<int>> t = {6, -1, 22};
    for (int i = 0; i <5 ; ++i)
        t.insert2(rand() % 101);
  
    t.print();

    dfs(t.root);

    dfs_post(t.root);
    t.postorder();

    dfs_inorder(t.root);

    return 0;
}