#include <iostream>
#include <memory>

//it is used to replace placement new
struct A
{
    A() {
        std::cout << "ctor()\n";
    }
    ~A() {
        std::cout << "dtor()\n";
    }
    int a_;
    A(int a): a_(a)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
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
