#ifndef __TREE_H_
#define __TREE_H_
#include <iostream>

namespace myds
{
   template<class T>
       class tree
         {
            struct node
              {
                 node *left, *right;
                 T data;
                 node(const T &d): data(d), left(nullptr), right(nullptr) {}
              };

            node *root;
            void _insert(node *&p,T d)
              {
                 if (p == nullptr)
                   {
                      p = new node(d);
                      return;
                   }
                 if (d < p->data)
                   _insert(p->left, d);
                 else if (d > p->data)
                   _insert(p->right, d);
              }

            void _inorder(node *p)
              {
                 if (p == nullptr) return;
                 _inorder(p->left);
                 std::cout << p->data << std::endl;
                 _inorder(p->right);
              }
           public:
            tree(): root(nullptr) {}
            tree(const std::initializer_list<int> &l): root (nullptr)
              {
                 for (auto &x: l)
                   insert(x);
              }
            void insert(const T &d)
              {
                 _insert(root, d);
              }

            void inorder()
              {
                 _inorder(root);
              }
         };
}

#endif
