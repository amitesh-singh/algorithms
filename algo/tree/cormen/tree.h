#ifndef __TREE_H_
#define __TREE_H_
#include <iostream>

namespace myds
{
   template<class T>
       class tree
         {
           public:
            struct node
              {
                 node *left, *right;
                 T data;
                 node *parent;
                 node(const T &d): data(d), left(nullptr), right(nullptr), parent(nullptr) {}
              };

           protected:
            node *root;
            void _insert(node *&p,T d, node *par = nullptr)
              {
                 if (p == nullptr)
                   {
                      p = new node(d);
                      p->parent = par;
                      return;
                   }
                 if (d < p->data)
                   _insert(p->left, d, p);
                 else if (d > p->data)
                   _insert(p->right, d, p);
              }

            void _inorder(node *p)
              {
                 if (p == nullptr) return;
                 _inorder(p->left);
                 std::cout << p->data << std::endl;
                 _inorder(p->right);
              }

            void _preorder(node *p)
              {
                 if (p == nullptr) return;
                 std::cout << p->data << std::endl;
                 _preorder(p->left);
                 _preorder(p->right);
              }

            void _postorder(node *p)
              {
                 if (p == nullptr) return;
                 _postorder(p->left);
                 _postorder(p->right);
                 std::cout << p->data << std::endl;
              }

           node *_search(node *p, const T &d)
             {
                if (p == nullptr)
                  return nullptr;
                if (d == p->data)
                  return p;
                else if (d < p->data)
                  return _search(p->left, d);
                else if (d > p->data)
                  return _search(p->right, d);
                return nullptr;
             }

           void _deleteTree(node *&p)
             {
                if (!p) return;
                _deleteTree(p->left);
                _deleteTree(p->right);
                delete p;
                p = nullptr;
             }
           public:
            tree(): root(nullptr) {}
            ~tree()
              {
                 _deleteTree(root);
              }
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

            void preorder()
              {
                 _preorder(root);
              }
            void postorder()
              {
                 _postorder(root);
              }

            node *search(const T &d)
              {
                 return _search(root, d);
              }
         };
}

#endif
