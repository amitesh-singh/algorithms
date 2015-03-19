#include<iostream>

using namespace std;
#define F cout << __PRETTY_FUNCTION__ <<endl
class A
{
    public:
    A()
    {
        F;
    }
    A operator()()
    {
        F;
    }
    A operator()(int a)
    {
        F;
    }
};
template<class T>
void callme(T func,int a)
{
    func(a);
}
int main()
{
    A aa;
    aa.operator()();
    aa();
    callme(aa,10);
    return 0;
}
