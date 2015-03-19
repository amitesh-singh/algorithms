#ifndef _MODEL_H
#define _MODEL_H
#include "priv.h"

class Model
{
   Data *d;
   Data *d_start, *d_end;
   int n;
   int v_n;
   deque< Data *> rail;

public:
   Signal1< DataChangeInfo **> sUpdate;
   Signal2< DataChangeInfo **, bool > sShow;

   Model(int n);
   //Initialize rail
   void Init();
   
   void MoveStep(Direction dir);
  

};

#endif