#include<iostream>
#include <string>

using namespace std;

const static int ALPHABETIC_SIZE = 26;

struct node
{
   node *children[ALPHABETIC_SIZE];
   char c;
   bool isLastWord;

   node(bool lastword = false, char _c = '-'):isLastWord(lastword), c(_c)
     {
        //cout << __func__ << ": adding char: " << c << endl;
        for (int i = 0; i < ALPHABETIC_SIZE; ++i)
          children[i] = 0;
     }
};

void insert(node *&root, string key)
{
   if (root == 0)
     root = new node();

   node *tmp = root;

   for (int i = 0; i < key.length(); ++i)
     {
        int index = key[i] - 'a';
       // cout << key[i] << endl;

        if (!tmp->children[index])
          tmp->children[index] = new node(false, key[i]);
         tmp = tmp->children[index];
     }

   if (tmp) tmp->isLastWord = true;
}


void printTrie(node *root)
{
   if (root == 0) return;

   cout << root->c << ":" << root->isLastWord << endl;
   for (int i =0; i < ALPHABETIC_SIZE; ++i)
     {
        printTrie(root->children[i]);
     }
}

bool search(node *root, string key)
{
   if (root == 0) return false;

   node *tmp = root;

   for (int i = 0; i < key.length(); ++i)
     {
        int index = key[i] - 'a';
        if (!tmp->children[index])
          return false;

        tmp = tmp->children[index];
     }

   return (tmp && tmp->isLastWord);
}

bool haveChildren(node *root)
{
   for (int i = 0; i < ALPHABETIC_SIZE; ++i)
     {
        if (root->children[i])
          return true;
     }

   return false;
}

bool remove(node *&curr, string key)
{
   if (curr == 0) return false;

   if (key.length())
     {
        int index = key[0] - 'a';
        if (curr && curr->children[index] &&
            remove(curr->children[index], key.substr(1)) &&
            curr->isLastWord == false)
          {
             if (!haveChildren(curr))
               {
                  delete curr;
                  curr = 0;
                  return true;
               }
             else
               return false;
          }
     }
   if (key.length() == 0 && curr->isLastWord)
     {
        if (!haveChildren(curr))
          {
             delete curr;
             curr = 0;
             return true;
          }
        else
          {
             curr->isLastWord = false;
             return false;
          }
     }

   return false;
}

int main()
{
   node *root = 0;

   insert(root, "ami");
   insert(root, "amit");
   insert(root, "aaru");
   insert(root, "avi");

   printTrie(root);
   cout << "searching for ami: " << search(root, "ami") << endl;
   cout << "searching for some: " << search(root, "some") << endl;
   cout << "searching for amit: " << search(root, "amit") << endl;
   cout << "searching for avi: " << search(root, "avi") << endl;
   cout << "searching for avit: " << search(root, "avit") << endl;

   cout << "deleting amit: " << remove(root, "amit") << endl;
   cout << "searching for amit: " << search(root, "amit") << endl;

   printTrie(root);

   return 0;
}
