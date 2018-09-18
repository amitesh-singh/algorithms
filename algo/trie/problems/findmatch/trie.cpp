//question: find the matching number into trie
// e.g.
//  12345
//  12355 --> ok
//  12345 --> ok
//  12233 -> not ok.
// find the exisiting numbers added into trie
//
#include <iostream>
using namespace std;

int charToInt(char c)
{
   if (c == '0')
     return 0;
   else if (c == '1')
     return 1;
   else if (c == '2')
     return 2;
   else if (c == '3')
     return 3;
   else if (c == '4')
     return 4;
   else if (c == '5')
     return 5;
   else if (c == '6')
     return 6;
   else if (c == '7')
     return 7;
   else if (c == '8')
     return 8;
   else if (c == '9')
     return 9;
}

static const unsigned char ALPHASIZE = 10;
struct node
{
   bool isLeaf;
   node *children[ALPHASIZE];

   node (bool leaf = false): isLeaf(leaf)
   {
      for (int i = 0; i < ALPHASIZE; ++i)
        {
           children[i] = 0;
        }
   }
};

node mempool[1000];
unsigned int memIndex = 0;

int strLen(const char *str)
{
   const char *p = str;
   while (*p) p++;
   return p - str;
}

int trieSize = 0;
void insert(node *&root, char key[])
{
   if (root == 0)
     root = new (mempool + memIndex++) node();

   node *tmp = root;

   int index = 0;
   int len = strLen(key);
   for (int i = 0; i < len; ++i)
     {
        index = charToInt(key[i]);
        if (!tmp->children[index])
          tmp->children[index] = new (mempool + memIndex++) node();
        tmp = tmp->children[index];
     }

   trieSize++;
   tmp->isLeaf = true;
}

bool  search(node *root, char key[], int firstMismatch)
{
   if (root == 0) return false;

   int index = 0;
   int len = strLen(key);
   for (int i  = 0; i < len; ++i)
     {
        index = charToInt(key[i]);
        //this is null
        if (root && !root->children[index])
          {
             if (!firstMismatch)
               {
                  firstMismatch++;
                  for (int j = 0; j < ALPHASIZE; ++j)
                    {
                       if (j != index)
                         {
                            if (search(root->children[j], key + i + 1, firstMismatch))
                              {
                                 return true;
                              }
                         }
                    }
               }
             else if (firstMismatch == 1)
               {
                  if (!root->children[index])
                    {
                       firstMismatch++;
                       return false;
                    }
               }

          }
        if (firstMismatch > 1) return false;
        if (root) root = root->children[index];
     }

   return (root && root->isLeaf);
}

char buf[11];
void intToString(int n)
{
   sprintf(buf, "%d", n);
}

int main()
{
   int T;
   int Q;
   int command;
   int number;
   int firstMismatch = 0;

   node *root = 0;

   freopen("input.txt", "r", stdin);
   cin >> T;

   for (int test_case = 1; test_case <= T; ++test_case)
     {
        cin >> Q;
        cout << "#" << test_case << " ";
        root = 0;
        trieSize = 0;

        for (int n = 1; n <= Q; ++n)
          {
             cin >> command;
             if (command == 1)
               {
                  cin >> number;
                  intToString(number);
                  firstMismatch = 0;
                  if (!search(root, buf, firstMismatch))
                    insert(root, buf);
               }
             else if (command == 2)
               {
                  cout << trieSize << " ";
               }
          }
        cout << "\n";
     }

}
