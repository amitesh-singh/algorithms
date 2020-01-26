#include "animal.h"

int main()
{
    Animal *sparky = new Dog("sparky");
    Animal *tweety = new Bird("tweety");

    cout << sparky->GetName(); 
    sparky->MakeSound();
    sparky->MakeFly();

    cout << tweety->GetName();
    tweety->MakeSound();
    tweety->MakeFly();

    delete sparky;
    delete tweety;

    return 0;
}