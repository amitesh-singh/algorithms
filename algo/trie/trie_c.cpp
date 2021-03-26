#include <iostream>

using namespace std;

#define ALPHA_SIZE 26

int mstrlen(const char *str)
{
   const char *p = str;

   while (*p) p++;

   return p - str;
}

//
// First node is '-'
//
//
struct node
{
   char c;
   bool isLast;
   node *children[ALPHA_SIZE];

   node(char key = '-', bool flag = false): c(key), isLast(flag)
   {
      for (int i = 0; i < ALPHA_SIZE; ++i)
        {
           children[i] = nullptr;
        }
   }
};

void insert(node *&root, const char *key)
{
   if (root == nullptr) root = new node();
   int n = mstrlen(key);

   node *tmp = root;
   for (int i = 0; i < n; ++i)
     {
        int index = key[i] - 'a';
        if (!tmp->children[index])
          tmp->children[index] = new node(key[i], false);
        tmp = tmp->children[index];
     }

   tmp->isLast = true;
}

bool search(node *&root, const char *key)
{
   if (root == nullptr) return false;
   int n = mstrlen(key);

   node *tmp = root;

   for (int i = 0; i < n; ++i)
     {
        int index = key[i] - 'a';
        if (!tmp->children[index])
          return false;
        tmp = tmp->children[index];
     }

   return (tmp && tmp->isLast);
}

bool remove(node *&root, const char *key)
{
   auto hasChildren = [](node *root)->bool {
        if (root == nullptr) return false;
        for (int i = 0; i < ALPHA_SIZE; ++i)
          {
             if (root->children[i])
               return true;
          }
        return false;
   };
   if (!root) return false;
   if (*key)
     {
        int index = key[0] - 'a';
        if (root && root->children[index] &&
            remove(root->children[index], key + 1) &&
            !root->isLast)
          {
             if (!hasChildren(root))
               {
                  delete root;
                  root = nullptr;
                  return true;
               }
             else
               return false;
          }
     }
   if (*key == '\0' && root->isLast)
     {
        if (!hasChildren(root))
          {
             delete root;
             root = nullptr;
             return true;
          }
        else
          {
             root->isLast = false;
             return false;
          }
     }
   return false;
}

void clean(node *&root)
{
   if (root == nullptr) return;
   for (int i = 0; i < ALPHA_SIZE; ++i)
     {
        if (root->children[i])
          clean(root->children[i]);
     }

   cout << "deleting: " << root->c << " ";
   delete root;
   root = nullptr;
}

int main()
{
   node *root = 0;

   insert(root, "amit");
   insert(root, "ami");
   insert(root, "avi");

   cout << "Searching for ami: " << search(root, "ami") << endl;
   cout << "Searching for amitesh: " << search(root, "amitesh") << endl;
   insert(root, "rvisfkn");

   clean(root);

   cout << endl;

   return 0;
}
