#include<iostream>
using namespace std;
#define F cout << __PRETTY_FUNCTION__ << endl

class Base
{
    protected:

    void func1()
    {
        F;
    }
    void func2()
    {
        F;
    }
    virtual void step1() = 0;
    virtual void step2() = 0;
    public:

    void execute()
    {
        func1();
        step1();
        func2();
        step2();
    }
   
};
class One:public Base
{
    public:
    void step1()
    {
        F;
    }
    void step2()
    {
        F;
    }
};
class Two: public Base
{
    public:
    void step1()
    {
        F;
    }
    void step2()
    {
        F;
    }
};



int main()
{
    Base *b[2] = {new One,new Two};
    b[0]->execute();
    b[1]->execute();

    delete b[0];
    delete b[1];


    return 0;
}
