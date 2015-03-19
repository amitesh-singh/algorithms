#define _SIGSLOT_SINGLE_THREADED
#include <iostream>
#include "sigslot.h"

#define F std::cout << __func__ << std::endl;

class Switch
{
public:
   signal0<void> Clicked;
};

class Light: public has_slots<>
{
public:
   void ToggleState()
   {
      F;
   }
   void TurnOn()
   {
      F;
   }
   void TurnOff()
   {
      F;
   }
};


int main(int argc, char **argv)
{
   Switch sw1, sw2;
   Light l1, l2;

   sw1.Clicked.connect(&l1, &Light::ToggleState);
   sw2.Clicked.connect(&l2, &Light::ToggleState);

   Switch all_on, all_off;
   Light l3, l4;

   all_on.Clicked.connect(&l1, &Light::TurnOn);
   all_on.Clicked.connect(&l2, &Light::TurnOn);
   all_on.Clicked.connect(&l3, &Light::TurnOn);
   all_on.Clicked.connect(&l4, &Light::TurnOn);

   all_on.Clicked();

   return 0;
}