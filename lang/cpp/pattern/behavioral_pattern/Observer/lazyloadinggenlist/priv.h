#ifndef _PRIV_H
#define _PRIV_H

#include <iostream>
#include <string>
#include <deque>

#include "../Signals/_Signal.h"
using namespace Gallant;
using namespace std;

struct Data
{
   int n;
};

enum Direction
{
   UP,
   DOWN
};
struct DataChangeInfo
{
   deque< Data *> *d;
   Data *add_item;
   Data *del_item;
   DataChangeInfo(): d(0), add_item(0), del_item(0)
   {
   }
};

#endif