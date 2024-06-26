#include <iostream>
#include "tree.h"
#include <queue>


struct mytree: public myds::tree<int, myds::basicnode<int> >
{
    using node = myds::basicnode<int>;
    private:
    void _printgivenlevel(node *p, int level, int &actuallevel)
    {
        if (!p) return;
        if (level == actuallevel) std::cout << p->data << std::endl;

        _printgivenlevel(p->left, level + 1, actuallevel);
        _printgivenlevel(p->right, level + 1, actuallevel);
    }
    public:
    void bfs()
    {
        int levels = height();
        for (int i = 1; i <= levels; ++i)
            _printgivenlevel(root, 1, i);
    }

    void bfs2()
      {
         std::queue<node *> q;
         node *p = root;

         q.push(p);
         while (!q.empty())
           {
              node *curr = q.front();
              q.pop();
              std::cout << curr->data << ", ";

              if (curr->left) q.push(curr->left);
              if (curr->right) q.push(curr->right);
           }
         std::cout << '\n';
      }


    //separation of levels
    void bfs_level()
      {
         node *p = root;
         std::queue<node *> q;
         q.push(p);
         int n;
         int level = 1;
         while (!q.empty())
           {
              n = q.size();
              std::cout << "level: " << level << ": ";
              for (int i = 0; i < n; ++i)
                {
                   node *curr = q.front();
                   if (curr->left) q.push(curr->left);
                   if (curr->right) q.push(curr->right);
                   std::cout << curr->data << ", ";

                   q.pop();
                }
              std::cout << "\n";
              level++;
           }
         std::cout << '\n';
      }

    void printbfs_level(int level)
      {
         int currLevel = 1;
         std::queue<node *> q;
         node *p = root;

         q.push(p);

         while (!q.empty())
           {
              int n = q.size();
              for (int i = 0; i < n; ++i)
                {
                   node *curr = q.front();
                   if (curr->left) q.push(curr->left);
                   if (curr->right) q.push(curr->right);
                   if (level == currLevel)
                     std::cout << curr->data << " , ";
                   q.pop();
                }
              currLevel++;
           }
         std::cout << "\n";
      }

    void printLeftView()
      {
         node *p = root;
         std::queue<node *> q;

         q.push(p);

         while (!q.empty())
           {
              int n = q.size();

              for (int i = 0; i < n; ++i)
                {
                   node *curr = q.front();
                   if (curr->left) q.push(curr->left);
                   if (curr->right) q.push(curr->right);

                   if (i == 0) std::cout << curr->data << ", ";
                   q.pop();
                }
           }
         std::cout << std::endl;
      }

    void printRightView()
      {
         node *p = root;
         std::queue<node *> q;
         q.push(p);

         while (!q.empty())
           {
              int n = q.size();
              for (int i = 0; i < n; ++i)
                {
                   node *curr = q.front();
                   if (curr->right) q.push(curr->right);
                   if (curr->left) q.push(curr->left);

                   if (i == 0) std::cout << curr->data << ", ";
                   q.pop();
                }
           }
         std::cout << std::endl;
      }
};

#include <ctime>

int main()
{
   std::srand(std::time(nullptr));
   mytree mt;
   for (int i = 0; i < 40; ++i)
     mt.insert(std::rand() % 101);
   mt.print();

   //mt.bfs();
   std::cout << "bfs using queue:\n";
   mt.bfs2();

   std::cout << "bfs level wise\n";
   mt.bfs_level();

   std::cout << "print 2 level\n";
   mt.printbfs_level(2);

   std::cout << "print left view\n";
   mt.printLeftView();

   std::cout << "print right view\n";
   mt.printRightView();
   return 0;
}
