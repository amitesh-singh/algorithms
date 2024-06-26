//Class Template Argument Deduction(CTAD) 
/*
CTAD, or Class Template Argument Deduction, is a feature introduced in C++17 and further refined in C++20.
 CTAD allows you to omit template arguments when creating an instance of a class template, and the compiler 
 will deduce those template arguments based on the constructor arguments.

In C++20, CTAD was extended to support deduction guides for class templates. A deduction guide provides 
information to the compiler on how to deduce template arguments for a class template. The deduction guide 
is typically a separate declaration that helps the
 compiler infer the template arguments correctly.

 The compiler automatically generates guides that map each constructor call argument to a template argument.
*/

#include <iostream>

template<typename T>
struct container
{
    T data;
    container(T&& d): data(d) {}
    auto print()
    {
        std::cout << data << '\n';
    }
};

//define CTAD, so that we could do 
// container c(19);
// Constructor match -> Template instance
template<typename T>
container(T)->container<T>;

template<typename T1, typename T2>
struct pair
{
    T1 first;
    T2 second;
};


template<typename T1, typename T2>
pair(T1, T2)->pair<T1, T2>;

int main()
{
    //below line will compile with C++20, but not in c++17
    //g++ lang/cpp20/template_auto/ctad.cpp -std=c++20
    //container t(10);

    //to compile it in C++17, use CTAD like above
    container c = 10;
    c.print();

    container c2(29);
    c2.print();

    pair p1{1, 2.0};

    return 0;
}
