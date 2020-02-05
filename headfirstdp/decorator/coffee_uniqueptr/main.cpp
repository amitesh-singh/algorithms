#include <iostream>
using namespace std;
#include <memory>

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
    std::unique_ptr<Beverage> _beverage;
    Soy(std::unique_ptr<Beverage> b): _beverage(std::move(b)) {}
    virtual string getDesc()
    {
        return _beverage->getDesc() + ", Soy";
    }

    virtual double cost()
    {
        return _beverage->cost() + 1.5;
    }
    virtual ~Soy() = default;
};

class AlmondMilk : public AddOnDecorator
{
    public:
    std::unique_ptr<Beverage> _beverage;
    AlmondMilk(std::unique_ptr<Beverage> b) : _beverage(std::move(b))
    {
    }

    virtual ~AlmondMilk() = default;

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
    std::unique_ptr<Beverage> beverage {new Espresso};
    
    //{AlmondMilk{Espresso}}
    std::unique_ptr<Beverage> beverage2 = std::make_unique<AlmondMilk>(std::move(beverage));
    cout << beverage2->getDesc() << ": " << beverage2->cost() << endl;

    //{Soy(AlmondMilk{Espresso})}
    beverage2 = std::make_unique<Soy>(std::move(beverage2));
    cout << beverage2->getDesc() << ": " << beverage2->cost() << endl;

    return 0;
}
