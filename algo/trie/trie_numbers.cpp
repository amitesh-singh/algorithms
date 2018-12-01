//this shows how  to store numbers into a Trie
#include <iostream>

using namespace std;

int strLen(char *str)
{
   const char *p = str;

   while (*p) p++;

   return p - str;
}


#define ALPHA_SIZE 10
struct node
{
   char c;
   bool isLeaf;
   node *children[ALPHA_SIZE];


   node(bool leaf = false, char _c = '-'): isLeaf(leaf), c(_c)
   {
      for (register int i = 0; i < ALPHA_SIZE; ++i)
        {
           children[i] = nullptr;
        }
   }
};

void insert(node *&root, char key[])
{
   if (root == 0)
     root = new node();

   node *tmp = root;

   int len = strLen(key);

   for (int i = 0; i < len; ++i)
     {
        int index = key[i] - '0';
        if (!tmp->children[index])
          tmp->children[index] = new node(false, key[i]);

        tmp = tmp->children[index];
     }

   tmp->isLeaf = true;
}

bool search(node *root, char key[])
{
   if (root == 0) return false;

   int len = strLen(key);
   node *tmp = root;
   for (int i = 0; i < len; ++i)
     {
        int index = key[i] - '0';
        if (!tmp->children[index])
          return false;
        tmp = tmp->children[index];
     }

   return (tmp && tmp->isLeaf);
}

void printTrie(node *root)
{
   if (!root) return;

   cout << root->c << ":" << root->isLeaf << endl;
   for (int i = 0; i < ALPHA_SIZE; ++i)
     {
        printTrie(root->children[i]);
     }
}

bool haveChildren(node *root)
{
   for (int i = 0; i < ALPHA_SIZE; ++i)
   {
      if (root->children[i])
         return true;
   }

   return false;
}

bool remove(node *&root, char *key)
{
   if (root == 0)
   {
      return false;
   }
   int len = strLen(key);
   if (len)
   {
      int index = key[0] - '0';
      if (root && root->children[index] && remove(root->children[index], key + 1) && root->isLeaf == false)
      {
         if (!haveChildren(root))
         {
            delete root;
            root = 0;
            return true;
         }
         else
            return false;
      }
   }
   if (len == 0 && root->isLeaf == true)
   {
      if (!haveChildren(root))
      {
         delete root;
         root = 0;
         return true;
      }
      else
      {
         root->isLeaf = false;
         return false;
      }
   }

   return false;
}

int main()
{
   node *root = 0;

   insert(root, "124");
   insert(root, "124578");
   insert(root, "123");
   insert(root, "4567");
   insert(root, "673456");

   cout << "124 exists? " << (search(root, "124") ? "Yes" : "No");
   cout << "\n";
   cout << "125 exists? " << (search(root, "125") ? "Yes" : "No");
   cout << "\n";

   printTrie(root);
   
   cout << "deleting..." << endl;
   remove(root, "124");

   printTrie(root);

   return 0;
}
