#include<iostream>
using namespace std;

class complex
{
    double _re,_im;
    public:
    complex(double re,double im):_re(re),_im(im){}
    complex operator+(complex rhs)
    {
        return complex(this->_re + rhs._re,this->_im + rhs._im);
    }
    complex operator*(complex rhs)
    {
        return complex(this->_re * rhs._re,this->_im * rhs._im);
    }
    void operator+=(complex rhs)
    {
        cout << "Debug\n";
        //this->print();
        //rhs.print();
        this->_re = this->_re + rhs._re;
        this->_im = this->_im + rhs._im; 
        
        //return (*this + rhs);
    }
    void print()
    {
        cout << _re << "+" << _im << "i" << endl;
    }
};


int main()
{
    complex a(1.2,2.3),b(3.4,4.5);
    complex c = a + b; //shorthand
    complex c1 = a.operator+(b); //explicit call
    c.print();
    c1.print();
    complex d = a*b;
    d.print();
    d = a*b + complex(1.4,45.5);
    
    d.print();
    d+=a;
    d.print();
    d+=d;
    d.print();
    return 0;
}
