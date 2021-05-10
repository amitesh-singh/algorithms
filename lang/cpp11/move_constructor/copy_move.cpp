#include <iostream>

using namespace std;
#define F std::cout << __PRETTY_FUNCTION__ << std::endl

class A
{
    int a;
    public:
    A(const A &) = delete;
    
    //move constructor
    
    A(A &&rhs):a (rhs.a)
    {
        F;
    }
    
    A(int &&x):a(x) { F;}
    //copy constructor with rval ref
    //move copy constructor
    A &operator=(A &&rhs)
    {
        this->a = rhs.a;
        rhs.a = 0;
        F;
        return *this;
    }

    A &operator=(const A&rhs) = delete;

};

int main()
{
    A aa(2); //calls A(int &&);
    A aa2 (std::move(aa)); //calls A(A&&)
    A aa3 = A(3); //calls A(int &&)

    std::cout << "***\n";
    aa3 = A(4); //calls A(int &&) and then A &operator=(A&&)

    return 0;
}