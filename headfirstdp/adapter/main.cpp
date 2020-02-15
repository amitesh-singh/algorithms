#include <iostream>
using namespace std;

class Duck
{
    public:
    virtual void quack() = 0;
    virtual void fly() = 0;
};

class WildDuck: public Duck
{
    public:
    void quack()
    {
        cout <<  "WildDuck-" << "quack\n";
    }

    void fly()
    {
        cout << "WildDuck-" << "Fly\n";
    }

};

class CityDuck: public Duck
{
    public:
    void quack()
    {
        cout << "CityDuck-" << "quack\n";
    }

    void fly()
    {
        cout << "CityDuck-" << "fly\n";
    }
};

class Turkey
{
    public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

class WildTurkey: public Turkey
{
    public:
    void gobble()
    {
        cout << "WildTurkey-" << "gobble\n";
    }

    void fly()
    {
        cout << "WildTurkey-" << "fly\n";
    }
};

class TurkeyAdapter: public Duck
{
    Turkey *turkey;
    public:
    TurkeyAdapter(Turkey *t) : turkey(t) {}
    void quack()
    {
        turkey->gobble();
    }

    void fly()
    {
        for (int i = 0; i < 4; ++i)
            turkey->fly();
    }
};

int main()
{
    Duck *cityDuck = new CityDuck();
    cityDuck->fly();
    cityDuck->quack();

    Turkey *realTurkey = new WildTurkey();
    Duck *turkey = new TurkeyAdapter(realTurkey);
    turkey->quack();
    turkey->fly();

    delete turkey;
    delete realTurkey;
    delete cityDuck;

    return 0;
}