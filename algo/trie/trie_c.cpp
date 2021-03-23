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
        if (!tmp->children[i])
          tmp->children[i] = new node(key[i], false);
        tmp = tmp->children[i];
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
        if (!tmp->children[i])
          return false;
        tmp = tmp->children[i];
     }

   return (tmp && tmp->isLast);
}

int main()
{
   node *root = 0;

   insert(root, "amit");
   insert(root, "ami");

   cout << "Searching for ami: " << search(root, "ami") << endl;
   cout << "Searching for amitesh: " << search(root, "amitesh") << endl;

   return 0;
}
