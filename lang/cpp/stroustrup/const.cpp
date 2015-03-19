#include<iostream>
#include<typeinfo>
using namespace std;
class A
{
    int a;
    public:
    A():a(10)
    {
    }
    void changeA(int _a) const
    {
        //_a = 10; // error
        cout << typeid(this).name() << endl;
        A *ptr = const_cast<A*>(this);
        ptr->a = _a;
    }
    void print() const
    {
        cout << a << endl;
    }
};
int main()
{
    A aa;
    aa.changeA(11);
    aa.print(); //ok

    const A Caa;
    Caa.changeA(12);//undefined behavior
    Caa.print();
    return 0; 
}

