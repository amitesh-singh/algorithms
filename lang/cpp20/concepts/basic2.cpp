#include <iostream>
#include <concepts> //std::integral concept is defined in this header

template<typename T> requires std::integral<T>
auto add(T a, T b)
{
    return a + b;
}

//This shows how to define two concepts constrains
template<typename T>
concept concept_1 = true;

template<typename T>
concept concept_2 = true;

template<typename T>
requires (concept_1<T> and concept_2<T>)
auto add2(T a, T b)
{
    return a + b;
}

// not just concepts, as we can add other compile time checks too
//The below function has been restricted to working only with
// integral types that are at least 32 bit.
template<typename T>
requires(std::integral<T> and sizeof(T) >= 4)
void foo(T) {}


int main()
{
    std::cout << add(10, 20) << '\n';
    std::cout << add2(20, 30) << '\n';
    return 0;
}