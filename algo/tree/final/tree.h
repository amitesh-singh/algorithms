#ifndef __TREE_H_
#define __TREE_H_
#include <iostream>

namespace myds
{
  enum class tree_type
    {
       BST,
       AVL
    };

  template <class T>
   struct basicnode
    {
                 basicnode<T> *left, *right;
                 T data;
                 basicnode<T> *parent;
                 basicnode(const T &d): data(d), left(nullptr), right(nullptr), parent(nullptr) {}
    };

   template<class T, class node, tree_type treeType = tree_type::BST >
       class tree
         {
           public:

            node *root;
           protected:
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
             insert(p->data);
             _preorder_copy(p->left, t2);
             _preorder_copy(p->right, t2);
           }

           void _copy(const tree<T, node> &t)
           {
             _preorder_copy(t.root, t);
           }

           bool __isequal(const node *p1, const node *p2)
             {
                if (!p1 && !p2) return true;
                else if (p1 && !p2) return false;
                else if (!p1 && p2) return false;
                else if (p1 && p2)
                  {
                     return p1->data == p2->data && __isequal(p1->left, p2->left) && __isequal(p1->right, p2->right);
                  }
                return false;
             }

           bool _isequal(const tree<T, node> &t1, const tree<T, node> &t2)
             {
                return __isequal(t1.root, t2.root);
             }

           void __getMin(node *p, node *&res)
             {
                if (p && !p->left) { res = p;  return; }
                else
                  __getMin(p->left, res);
             }
           node *_getMin(node *p)
             {
                node *res;
                //go left side.
                __getMin(p, res);

                return res;
             }

           void __getMax(node *p, node *&res)
             {
                if (p && !p->right)
                  {
                     res = p;
                     return;
                  }
                else
                  __getMax(p->right, res);
             }

           node* _getMax(node *p)
             {
                node *res;
                __getMax(p, res);
                return res;
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
            tree(tree<T, node> &&rhs) : root(nullptr)
            {
              root = rhs.root;
              rhs.root = nullptr;
            }
            
            tree &operator=(tree<T, node> &rhs)
            {
              _copy(rhs);

              return *this;
            }

            tree &operator=(tree<T, node> &&rhs)
            { 
              root = rhs.root;
              rhs.root = nullptr;
              return *this;
            }

            void insert(const T &d)
              {
                 _insert(root, d);
              }
            void insert2(const T &d)
              {
                 node *curr = root;
                 if (curr == nullptr)
                   {
                      root = new node(d);
                      return;
                   }
                 while (curr != nullptr)
                   {
                      if (d < curr->data)
                        {
                           if (curr->left)
                             curr = curr->left;
                           else
                             {
                                //insert here
                                curr->left = new node(d);
                                curr->left->parent = curr;
                                break;
                             }
                        }
                      else if (d > curr->data)
                        {
                           if (curr->right)
                             curr = curr->right;
                           else
                             {
                                //insert here
                                curr->right = new node(d);
                                curr->right->parent = curr;
                                break;
                             }
                        }
                        else
                        {
                          //not adding dupilicates
                          break;
                        }
                   }
              }
            
            void _erase(node *&p, const T &d)
            {
              if (p == nullptr) return;
              if (d > p->data)
              {
                _erase(p->right, d);
              }
              else if (d < p->data)
              {
                _erase(p->left, d);
              }
              else if (p->left && p->right)
              {
                p->data = _getMin(p->right)->data;
                _erase(p->right, p->data);
              }
              else
              {
                node *tmp = p;
                if (p->left)
                  p = p->left;
                else
                  p = p->right;
                delete tmp;
                tmp = nullptr;
              }
            }
            void erase(const T &d)
            {
              _erase(root, d);
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

            bool operator==(const tree &rhs)
              {
                 return _isequal(*this, rhs);
              }

            node *getMin()
              {
                 return _getMin(root);
              }

            node *getMax()
              {
                 return _getMax(root);
              }
         };
}

#endif
