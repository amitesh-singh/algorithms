#include <iostream>
using namespace std;

#define F cout << __PRETTY_FUNCTION__ << endl

class Beverage 
{
    public:
    virtual string getDesc() = 0;
    virtual double cost() = 0;
    virtual ~Beverage() = default;
};

class Espresso : public Beverage
{
    public:
    virtual string getDesc()
    {
        return "Espresso";
    }

    virtual double cost()
    {
        return 1.01;
    }
};

class Decaf: public Beverage
{
    public:
    virtual string getDesc()
    {
        return "Decaf";
    }

    virtual double cost()
    {
        return 2.00;
    }
};

//Skip the Decorator inheritance chain, use Beverage as Decorator
using AddOnDecorator = Beverage;

class Soy: public AddOnDecorator
{
    public:
    Beverage *_beverage;
    Soy(Beverage *b): _beverage(b) {}
    virtual string getDesc()
    {
        return _beverage->getDesc() + ", Soy";
    }

    virtual double cost()
    {
        return _beverage->cost() + 1.5;
    }
    virtual ~Soy()
    {
        #ifdef DEBUG
        F;
        #endif
        delete _beverage;
    }
};

class AlmondMilk : public AddOnDecorator
{
    public:
    Beverage *_beverage;
    AlmondMilk(Beverage *b) : _beverage(b)
    {

    }

    virtual ~AlmondMilk()
    {
        #ifdef DEBUG
        F;
        #endif
        delete _beverage;
    }

    virtual string getDesc()
    {
        return _beverage->getDesc() + ", AlmondMilk";
    }

    virtual double cost()
    {
        return _beverage->cost() + 2.4;
    }
};

int main()
{
    Beverage *b1 = new Soy(new Espresso());

    cout << b1->getDesc() << ": " << b1->cost() << endl;
    delete b1;

    Beverage *b2 = new AlmondMilk(new AlmondMilk(new Decaf()));

    cout << b2->getDesc() << " : " << b2->cost() << endl;   
    delete b2;
    //no memory leak, but i can't define local variables.
    // double free mem corruption
    // Beverage beverage;
    // Almond milk (&beverage);

    return 0;
}
