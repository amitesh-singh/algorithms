#include <iostream>

template<typename T>
concept always_true = true;

// below code always compiles
template<typename T> requires always_true<T>
void add(T a, T b)
{
    std::cout << (a + b) << '\n';
}

template<typename T>
concept always_false = false;

//below code won't compile
template<typename T> requires always_false<T>
void add2(T a, T b)
{
}

int main()
{
    add(10, 20);
    add2(10, 20);
    return 0;
}