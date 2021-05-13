#include <iostream>
#define F std::cout << __PRETTY_FUNCTION__ << std::endl

//won't work for class objects

//global mem
void *operator new(size_t size)
{
    F;
    return std::malloc(size);
}

void *operator new[](size_t size)
{
    F;
    std::cout << "size is " << size << std::endl;
    return std::malloc(size);
}

void operator delete(void *ptr)
{
    F;
    std::free(ptr);
}

void operator delete[](void *ptr)
{
    F;
    std::free(ptr);
}

void *operator new(size_t size, int c)
{
    F;
    std::cout << c << std::endl;
    return std::malloc(size);
}

int main()
{
    int *p = new int;

    delete p;
    int *parr = new int[10];
    delete [] parr;

    int *p2 = new (10) int;
    delete p2;

    return 0;
}