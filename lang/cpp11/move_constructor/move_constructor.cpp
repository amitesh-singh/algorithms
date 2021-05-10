#include <iostream>
#define F std::cout << __PRETTY_FUNCTION__ << std::endl

struct A
{
    A()
    {
        _ptr = new int;
        F;
    }

    ~A()
    {
        F;
        delete _ptr;
    }

    //copy constructor 
    A(const A &rhs)
    {
        _ptr = new int;
        //deep copy
        *_ptr = *rhs._ptr;
        F;
    }

    //move contructor
    A(A &&rhs)
    {
        _ptr = rhs._ptr;
        rhs._ptr = nullptr;
        F;
    }

    private:
    int *_ptr;
};
#include <vector>

int main()
{
    std::vector<A> v;
    A a1;
    std::cout << "v.push_back(a1): \n";
    v.push_back(a1);
    std::cout << "********" << std::endl;

    A a2;
    std::cout << "v.push_back(std::move(a2): \n";
    v.push_back(std::move(a2));
    std::cout << "*******" << std::endl;

    A a3;
    std::cout << "v.emplace_back(a3): \n";
    v.emplace_back(a3);
    std::cout << "**********\n"; 

    A aa;
    std::cout << "A aa; v.push_back(std::move(a));\n";
    //this seems most efficient.
    v.push_back(std::move(aa));
    std::cout << "************\n";

    A a11;
    std::cout << "A a1; v.emplace_back(std::move(a1));\n";
    v.emplace_back(std::move(a11));
    std::cout << "****\n";
    
    return 0;
}