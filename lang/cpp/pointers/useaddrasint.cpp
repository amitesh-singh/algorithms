#include<iostream>
#define F cout << __PRETTY_FUNCTION__ << endl
using namespace std;
class A
{
    public:
    void get()
    {
        F;
    }
};
template<class T>
void useAddr(long addr)
{
    T *p =(T *) addr;
    F;
    cout << p << endl;
}

int main()
{
    int i = 1;
    F;
    cout << &i << endl;
    long addr = long(&i);
    useAddr<int>(addr);
    A aa;
    useAddr<A>(long(&aa));

    return 0;
}
