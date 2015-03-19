#include<iostream>

using namespace std;
#define F cout << __PRETTY_FUNCTION__ << ":" << __LINE__<< endl
struct A
{
    A()
    {
        F;
    }
    ~A()
    {
        F;
    }
};
template<class A>
struct gaurd
{
    A &a;
    gaurd(A &obj):a(obj)
    {
        F;
    }
    ~gaurd()
    {
        F;
        delete &a;
    }
};
template<typename T>
struct wrapper
{
    T _value;
    wrapper(T value):_value(value)
    {
        F;
    }
    ~wrapper()
    {
        F;
        delete _value;
    }
};
int main()
{

    try
    {
        F;
        //wrapper<int *> w(new int);
        // or
        int *p = new int;
        gaurd<int> gg(*p);
        throw 10;
    }
    catch(int a)
    {
        cout << "Catched\n";
        F;
        return 1;
    }
    return 0;
}
