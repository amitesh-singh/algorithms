#include <iostream>
using namespace std;


class IFlyBehavior
{
    public:
    virtual void fly() = 0;
};

class FlyNoWay : public IFlyBehavior
{
    public:
    void fly()
    {
        cout << "No Fly\n";
    }
};

class FlyWithWings: public IFlyBehavior
{
    public:
    void fly()
    {
        cout << "Fly with Wings.\n";
    }
};

class FlyWithJets: public IFlyBehavior
{
    public:
    void fly()
    {
        cout << "Fly with Jets.\n";
    }
};

class ITalkBehavior
{
    public:
    virtual void talk () = 0;
};

class Barking : public ITalkBehavior
{
    public:
    void talk()
    {
        cout << "Bho Bho\n";
    }
};

class Tweeting : public ITalkBehavior
{
    public:
    void talk()
    {
        cout << "Tweet tweet\n";
    }
};

class Mooing: public ITalkBehavior
{
    public:
    void talk()
    {
        cout << "moo, moo\n";
    }
};

class Animal
{
    protected:
    string _name;
    IFlyBehavior *_fb;
    ITalkBehavior *_tb;
    
    public:
    Animal(string name): _name(name) {}
    string GetName() { return _name; }
    virtual ~Animal()
    {
        delete _fb;
        delete _tb;
    }

    void MakeFly()
    {
        _fb->fly();
    }

    void MakeSound()
    {
        _tb->talk();
    }

    void SetTalkBehavior(ITalkBehavior *tb)
    {
        if (_tb) delete _tb;
        _tb = tb;
    }

    void SetFlyBehavior(IFlyBehavior *fb)
    {
        if (_fb) delete _fb;
        _fb = fb;
    }
};

class Dog: public Animal
{
    public:
    Dog(string name): Animal(name)
    {
        _fb = new FlyNoWay();
        _tb = new Barking();
    }
};

class Bird : public Animal
{
    public:
    Bird(string name) : Animal(name)
    {
        _fb = new FlyWithWings();
        _tb = new Tweeting();
    }
};

