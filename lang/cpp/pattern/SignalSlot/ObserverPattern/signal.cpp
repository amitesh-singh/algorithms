#include<iostream>
using namespace std;
#define cout << __PRETTY_FUNCTION__ << endl
/*
TODO

class Switch
{
    public:
    void onSwitch();
    signal1<int> sig_current;
};
class Light
{
    void LightOn(int color);
};

Switch sw1;
Light l1;

sw1.sig_current.connect(&l1,&Light::LightOn);
sw1.sig_current.emit();



*/
template<class param>
class signal1
{
    public:
    typedef void (*func)();
    void connect();
    
};
class A
{
    public:
    signal0<void> S1;
    A(signal0<void> &s_)S1(s_){F;}
};
class B
{
    public:
    void callme()
    {
        F;
    }
    
};
int main()
{


    return 0;
}
