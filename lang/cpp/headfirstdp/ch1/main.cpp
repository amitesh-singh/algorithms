#include "Duck.h"


int main()
{
   //mallard duck
   Duck *mallard = new MallardDuck();
   mallard->display();
   mallard->performQuack();
   mallard->performFly();
   mallard->setFlyBehavior(new FlyWithRocket());
   mallard->performFly();

   delete mallard;

   //super duck
   Duck *super = new SuperDuck();
   super->display();
   //first quack and then fly
   super->performQuack();
   super->performFly();

   delete super;

   return 0;
}