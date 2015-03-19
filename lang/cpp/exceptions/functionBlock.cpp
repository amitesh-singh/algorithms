#include<iostream>
using namespace std;
#define F cout << __PRETTY_FUNCTION__ << endl

void function1()
{
    try
    {
        throw 2;
    }
    catch(int a)
    {
        cout << "catched " << a << endl;
    }
}
void function2() try
{
    throw 2.5f;
}
catch(float f)
{
    F;
    cout << "catched : " << f << endl;
}
int main()
{
    function1();
    function2();

    return 0;
}
