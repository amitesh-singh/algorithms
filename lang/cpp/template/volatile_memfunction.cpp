#include<iostream>
using namespace std;


class X
{
    public:

        void display() throw(){cout<<endl<<"Display"<<endl;}
        void display() const throw(){cout<<endl<<"const Display"<<endl;}
        void display() volatile throw(){cout<<endl<<"volatile Display"<<endl;}
        void display() const volatile throw(){cout<<endl<<"volatile const Display"<<endl;}

};

int main()
{
    X x1;
    const X x2 = x1;
    volatile X x3;
    volatile const X x4 = x2;

    x1.display();
    x2.display();
    x3.display();
    x4.display();

    return 0;
}
