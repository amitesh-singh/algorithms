#include<iostream>
using namespace std;
class IProduct
{
    public:
    virtual void f() = 0;
};

class Product1: public IProduct
{
    public:
    void f() {}
};

class Product2: public IProduct
{
    public:
    void f() {}
};

class Framework
{
    public:
    virtual IProduct* makeProduct() = 0;
};

//this makes Product1
class App1: public Framework
{
    public:
    IProduct* makeProduct()
    {
        return new Product1();
    }
};

class App2: public Framework
{
    public:
    IProduct* makeProduct()
    {
        return new Product2();
    }
};

int main()
{
    App1 app1;
    IProduct *p1 = app1.makeProduct();
    p1->f();
    
    App2 app2;
    IProduct *p2 = app2.makeProduct();
    p2->f();

    return 0;
}
