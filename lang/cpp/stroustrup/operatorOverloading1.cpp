#include<iostream>
using namespace std;
#define F cout << __PRETTY_FUNCTION__ << endl
class A
{
    int _a;
    public:
    int getA()
    {
        return _a;
    }
    A(A const &_aa):_a(_aa._a){}
    A(int a):_a(a){}
    void operator+(int a)
    {
        F;
    }
    //postfix unary.
    //this int is never used. the argument is simply a dummy used to 
    //distingiush between prefix and postfix application.
    A operator++(int)
    {
        F;
        _a++;
        return *this;
    }
    //prefix notation
    A operator++()
    {
        F;
        _a++;
        return *this;
    }
    
    //prefix unary (depends upon the no. of argument
    A *operator&()
    {
        F;
        return this;
    }
    //binary &
    bool operator&(A aa)
    {
        F;
        return this->_a & aa._a;
    }

    //operator bool  -> if (A()) for this
    operator bool() const
    {
        return _a > 0;
    }

    A &operator=(int &&r)
    {
        F;
        _a = r;
        return *this;
    }
   
};
// ::operator&(aa);
// prefix unary but this results into infinite loop.
//fix : is there any other way to find out the address of A without using '&'?
/*
A *operator&(A const & aa)
{
    F;
    return &aa;
}
*/
void operator+(A a,A b)
{
    F;
}

int main()
{
    A aa(2);
    aa+1;
    //1+aa;
    A bb(1);
    bool ret= aa & bb;
    cout << ret;
    cout << &aa;
    bb++;
    cout << "\n";
    cout << bb.getA() << endl;
    ++bb;
    cout << bb.getA() << endl;
    
    if (aa) //calls 
    {
        std::cout << "greater than 0\n";
    }
    aa = 4;
    

    return 0;
}
