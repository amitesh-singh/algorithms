#include<iostream>
using namespace std;

#define F cout << __PRETTY_FUNCTION__ << endl

class Strategy;
class TravelToAirport
{
    protected:
    Strategy *st_;
    public:
    enum Type{BUS,CAR};
    TravelToAirport():st_(0){}
    void Travel(Type t);
    ~TravelToAirport()
    {
        delete st_;
    }
};

class Strategy
{
    public:
    virtual void drive() = 0;
};
class BusStrategy:public Strategy
{
    public:
    void drive()
    {
        F;
    }
};
class CarStrategy:public Strategy
{
    public:
    void drive()
    {
        F;
    }
};
void TravelToAirport::Travel(Type t)
{
    if(!st_)
        delete st_;
    switch(t)
    {
        case BUS:
        st_ = new BusStrategy();
        break;
        case CAR:
        st_ = new CarStrategy();
        break;
        default:
        st_ = new CarStrategy();
        break;
    }
    st_->drive();

}

int main()
{
    TravelToAirport ta;
    ta.Travel(TravelToAirport::BUS);
    ta.Travel(TravelToAirport::CAR);

    return 0;
}
