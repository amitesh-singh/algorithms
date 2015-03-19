#include <iostream>
#include "../Signals/_Signal.h"
using namespace Gallant;
enum Direction
{
   UP, DOWN
};
class Model
{
public:
   Signal0< void > show; /*! This sends signal to initiate show of 
                             View 
                         */
   void InitShow()
   {
      std::cout << "Model -> show view signal\n";
      show();
   }

   void Update(Direction dir)
   {
      std::cout << "View is update for " << dir << "\n" <<std::endl;
   }
};

class View
{
public:
   Signal1< Direction > update;
   void Show()
   {
      std::cout << "View is getting shown\n\n";
   }

   void Update(Direction dir)
   {
      //This updates model.
      std::cout << "sending update model signal " \
                   "from View to Model\n";
      update(dir);
   }
};

int main()
{
   View v;
   Model m;
   
   //connect both model and view 
   m.show.Connect(&v, &View::Show);
   v.update.Connect(&m, &Model::Update);
   m.InitShow();
   
   v.Update(UP);
   v.Update(DOWN);

   int c;
   std::cin >> c;

   return 0;
}