#include <iostream>
#include "../Signals/_Signal.h"
using namespace Gallant;
using namespace std;
#define F cout << __FUNCTION__ << endl;

class Model
{
public:
   Signal0< > sShow;
   void Load()
   {
      F;
      sShow();
   }
};

class View
{
public:
   void Show()
   {
      F;
   }
};

class Controller
{
   Model m;
   View v;

public:
   Controller()
   {
      m.sShow.Connect(&v, &View::Show);
   }
   void Run()
   {
      m.Load();
   }
};

int main()
{
   Controller c;

   c.Run();

   int x;
   cin >> x;

   return 0;
}