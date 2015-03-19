#include <iostream>
#include <string>
#include <deque>

#include "../Signals/_Signal.h"
using namespace Gallant;
using namespace std;

#define F std::cout << __FUNCTION__ << std::endl

struct Data
{
   int n;
};

enum Direction
{
   UP,
   DOWN
};

class Model
{
   Data *d;
   deque<Data *> rail; // rail which moves over d;

   int n;
   int v_n;
public:
   Signal1< deque <Data *>& > sInitShow;

   Model(int n)
   {
      //Load n number of data
      d = new Data[n];
      for (int i = 0; i < n; ++i)
      {
         d[i].n = i;
      }
      this->n = n;
   }

   void ShowFirstPage()
   {
      //first populate our dqueue
      v_n = 10; //todo: get it from view
      rail.clear();
      for (int i = 0; i < v_n; ++i)
      {
         rail.push_back(&d[i]);
      }

      //send signal to view.
      F;
      sInitShow(rail);
   }

   void ShowLastPage()
   {
      //first populate our dqueue
      v_n = 10; //todo: get it from view
      rail.clear();
      for (int i = (n - 1); i > (n - v_n); --i)
      {
         rail.push_front(&d[i]);
      }

      //send signal to view.
      F;
      sInitShow(rail);
   }

   void Update(Direction dir)
   {
      if (dir == UP)
      {
         rail.pop_back();
         int x = rail[0]->n - 1;
         if (x < 0)
         {
            cerr << "**********top of loop ********* \n";
            ShowLastPage();
            //sInitShow(rail);
            return;
         }
         rail.push_front(&d[x]);
      }
      else if (dir == DOWN)
      {
         rail.pop_front();
         int x  = rail.size() - 1;
         if (d[rail[x]->n].n == ( n - 1))
         {
            ShowFirstPage();
            return;
         }
         rail.push_back(&d[rail[x]->n + 1]);
      }
      sInitShow(rail);
   }
};

class View
{
   deque<int> d;
   Direction dir;

public:
   Signal1 < Direction > sUpdate;

   void InitShow(deque< Data *> &rail)
   {
      F;
      d.clear();
      for (unsigned int i = 0; i < rail.size(); ++i)
      {
         d.push_back(rail[i]->n);
      }
      Show();
   }
   void Show()
   {
      cout << "List **************\n";
      for (int i = 0; i < d.size(); ++i)
      {
        
         cout << "View::Show:" << d[i] << "\n";
         
      }
      cout << "List ***************\n";
   }

   void ProcessInput(char c)
   {
      if (c == 'u')
      {
         dir = UP;
         sUpdate(dir);
      }
      else if (c == 'd')
      {
         dir = DOWN;
         sUpdate(dir);
      }
      else
      {
         cerr << "***** enter up or down\n";
      }
   }
};

class App
{
   Model *m;
   View *v;

public:
   App()
   {
      m = new Model(100);
      v = new View();

      m->sInitShow.Connect(v, &View::InitShow);
      v->sUpdate.Connect(m, &Model::Update);
      F;
   }

   ~App()
   {
      m->sInitShow.Clear();
      v->sUpdate.Clear();

      delete m;
      delete v;
   }

   void Run()
   {
      m->ShowFirstPage();

      while (1)
      {
         char c;

         cin >> c;
         v->ProcessInput(c);
      }
   }
};