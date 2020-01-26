#ifndef DUCK_H
#define DUCK_H

#include <iostream>

#define F std::cout << __PRETTY_FUNCTION__ << std::endl

//lets define the behaviors
//This is our interface
class FlyBehavior
{
public:
  //interface function, the derived class must obliged to 
  // implement fly().
  virtual void fly() = 0;
};

class FlyWithWings: public FlyBehavior
{
public:
  void fly()
    {
       F;
    }
};

class FlyWithRocket: public FlyBehavior
{
public:
  void fly()
    {
       F;
    }
};

class FlyNoWay: public FlyBehavior
{
public:
  void fly()
    {
       //F; do nothing
    }
};

//This is an interface.
class QuackBehavior
{
public:
  virtual void quack() = 0;
};

class Quack: public QuackBehavior
{
public:
  void quack()
    {
       F;
    }
};

class MuteQuack: public QuackBehavior
{
public:
  void quack()
    {
       F;
    }
};

//This is a base class of a Duck
class Duck
{
protected:

  //The derived duck class implements the 
  // flybehaviour/quackbehavior
  FlyBehavior *fly;
  QuackBehavior *quack;

public:
  virtual ~Duck()
    {
       delete fly;
       delete quack;
    }

  void performFly()
    {
       fly->fly();
    }

  void performQuack()
    {
       quack->quack();
    }

  void setFlyBehavior(FlyBehavior *fb)
    {
       if (fly)
         delete fly;
       fly = fb;
    }

  void setQuackBehavior(QuackBehavior *qb)
    {
       if (quack)
         delete quack;
       quack = qb;
    }

  void swim()
    {
       std::cout << "Swimming.. woooooohhh!!\n";
    }
  void run()
    {
       std::cout << "Running ... rooooohhhh!!\n";
    }

  virtual void display() = 0;
};

class MallardDuck: public Duck
{
public:

  MallardDuck()
    {
       fly = new FlyWithWings();
       quack = new Quack();
    }


  void display()
    {
       std::cout << "I am Mallard Duck\n";
    }
};

class SuperDuck: public Duck
{
public:

  SuperDuck()
    {
       fly = new FlyWithRocket();
       quack = new Quack();
    }

  void display()
    {
       std::cout << "I am a Superduck\n";
    }
};

#endif
