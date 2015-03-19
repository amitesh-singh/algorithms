#include <iostream>
#include "../Signals/_Signal.h"
using namespace Gallant;

#define F std::cout << __FUNCTION__ << std::endl

class Switch
{
public:
   Signal0< void > Clicked;
};

class Light
{
public:
   void Toggle()
   {
      std::cout << this << " ";
      F;
   }
   void TurnOn()
   {
      std::cout << this << " ";
      F;
   }
   void TurnOff()
   {
      std::cout << this << " ";
      F;
   }
};

int main()
{
   Switch s1;
   Light l1, l2;

   s1.Clicked.Connect(&l1, &Light::Toggle);
   s1.Clicked.Connect(&l2, &Light::Toggle);

   s1.Clicked();
   
   Switch all_on, all_off;
   Light l3, l4;

   all_on.Clicked.Connect(&l1, &Light::TurnOn);
   all_on.Clicked.Connect(&l2, &Light::TurnOn);
   all_on.Clicked.Connect(&l3, &Light::TurnOn);
   all_on.Clicked.Connect(&l4, &Light::TurnOn);

   all_off.Clicked.Connect(&l1, &Light::TurnOff);
   all_off.Clicked.Connect(&l2, &Light::TurnOff);
   all_off.Clicked.Connect(&l3, &Light::TurnOff);
   all_off.Clicked.Connect(&l4, &Light::TurnOff);
   
   all_on.Clicked();
   all_off.Clicked();

   int c;
   std::cin >> c;

   return 0;
}
