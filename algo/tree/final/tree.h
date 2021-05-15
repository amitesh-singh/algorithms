#ifndef __TREE_H_
#define __TREE_H_
#include <iostream>

namespace myds
{
  template <class T>
   struct basicnode
    {
                 basicnode<T> *left, *right;
                 T data;
                 basicnode<T> *parent;
                 basicnode(const T &d): data(d), left(nullptr), right(nullptr), parent(nullptr) {}
    };

   template<class T, class node>
       class tree   
         {
           public:
          
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

           void _print(const node *p, const std::string &prefix, bool isLeft)
           {
             if (!p) return;
             std::cout << prefix; 
             std::cout << (isLeft ? "├──" : "└──" );
             std::cout << p->data << std::endl;

             _print(p->left, prefix + (isLeft ? "│   " : "    "), true);
             _print(p->right, prefix + (isLeft ? "│   ": "    "), false);
           }

           size_t _count(node *p)
           {
             if (!p) return 0;
             return _count(p->left) + _count(p->right) + 1;
           }

           size_t _height(node *p)
           {
             if (!p) return 0;
             return std::max(_height(p->left), _height(p->right)) + 1;
           }

           void _preorder_copy(node *p, const tree<T, node> &t2)
           {
             if (!p) return;
             //t2.insert(p->data);
             insert(p->data);
             _preorder_copy(p->left, t2);
             _preorder_copy(p->right, t2);
           }

           void _copy(const tree &t)
           {
             _preorder_copy(t.root, t);
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
            
            tree(const tree<T, node> &rhs) : root(nullptr)
            {
              _copy(rhs);
            }

            tree &operator=(const tree<T, node> &rhs)
            {
              _copy(rhs);

              return *this;
            }

            tree &operator=(tree<T, node> &&rhs)
            {

            }
            void insert(const T &d)
              {
                 _insert(root, d);
              }
            // Left, root, right
            void inorder()
              {
                 _inorder(root);
              }
            //Root, left, right 
            void preorder()
              {
                 _preorder(root);
              }
            //Left, right, root
            void postorder()
              {
                 _postorder(root);
              }

            node *find(const T &d)
              {
                 return _search(root, d);
              }
            
            void print()
            {
              std::cout << "\n";
              _print(root, "", false);
            }

            size_t size()
            {
              return _count(root);
            }

            size_t height()
            {
              return _height(root);
            }
         };
}

#endif
