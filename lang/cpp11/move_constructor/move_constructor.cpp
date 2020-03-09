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
    std::cout << "v.push_back(A()): \n";
    v.push_back(A());
    std::cout << std::endl;

    std::cout << "v.push_back(std::move(A()): \n";
    v.push_back(std::move(A()));
    std::cout << std::endl;

    std::cout << "v.emplace_back(A()): \n";
    v.emplace_back(A());

    A aa;
    std::cout << "A aa; v.push_back(std::move(a));\n";
    v.push_back(std::move(aa));
    std::cout << "************ main() exiting..\n";
    return 0;
}