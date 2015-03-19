#include<iostream>
using namespace std;
/*
dynamiccast1.cpp:18:34: warning: dynamic_cast of ‘B bb’ to ‘class A*’ can never succeed 
output: 0  - asked in macquire online test - I was right :-)
*/
class A
{
    public:
    virtual ~A(){}
};

class B
{
    public:
    virtual ~B(){}
};
int main()
{
    B bb;
    A *aa = dynamic_cast<A *>(&bb);
    cout << aa << endl;

    return 0;
}
