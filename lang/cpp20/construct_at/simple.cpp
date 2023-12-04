#include <iostream>
#include <memory> //std::construct_at defined under this header

//it is used to replace placement new
struct A
{
    A()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    ~A()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    A(int a): a_(a)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    int a_;
};

int main()
{
    alignas(sizeof(A)) unsigned char my_buffer[sizeof(A)];
    A *ptr = std::construct_at(reinterpret_cast<A*>(my_buffer));
    std::destroy_at(ptr);

    ptr = std::construct_at(reinterpret_cast<A*>(my_buffer), 10);
    std::destroy_at(ptr);

    return 0;
}
