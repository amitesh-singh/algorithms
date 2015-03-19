#include "Model.h"

Model::Model(int n)
{
   d = new Data[n];
   for (int i = 0; i < n; ++i)
   {
      d[i].n = i;
   }
}

void Model::Init()
{
   v_n = 10; //TODO: Get it from View.
   for(int i = 0; i < v_n; ++i)
   {
      rail.push_back(&d[i]);
   }
   d_start = &d[0];
   d_end = &d[v_n - 1];
   DataChangeInfo *dci = new DataChangeInfo();
   dci->d = &rail;
   sShow(&dci, true);
   cout << "Calling show ..\n";
}

void Model::MoveStep(Direction dir)
{
   if (dir == UP)
   {
      DataChangeInfo *dci = new DataChangeInfo();
      dci->d = &rail;
      int start = rail[0]->n;
      int end = rail[rail.size() - 1]->n;
      rail.push_front(&d[start - 1]);
      dci->add_item = &d[start - 1];
      rail.pop_back();
      dci->del_item = &d[end];

      sUpdate(&dci);
   }
   else if (dir == DOWN)
   {
      DataChangeInfo *dci = new DataChangeInfo();
      dci->d = &rail;
      int start = rail[0]->n;
      int end = rail[rail.size() - 1]->n;
      rail.push_back(&d[end]);
      dci->add_item = &d[end];
      rail.pop_front();
      dci->del_item = &d[start - 1];

      sUpdate(&dci);
   }
   else
   {
      cerr << "I don't know\n";
   }
}