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

class C: public A
{

};

int main()
{
    B bb; // dynamic cast would fail since B and A are not related. B
    // has to inherit from A;
    A *aa = dynamic_cast<A *>(&bb);
    cout << aa << endl;

    C cc;

    A *a1 = dynamic_cast<A *>(&cc);

    std::cout << a1 << std::endl;

    return 0;
}
