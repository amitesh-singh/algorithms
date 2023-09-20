#include <iostream>
#include <concepts>

template<typename T>
concept can_add = requires (T a)
{
    requires std::integral<T>;
    requires sizeof(T) >= sizeof(int);
    { a + a } noexcept -> std::same_as<T>;
};
/*
you may be wondering why the requires keyword appears multiple times. 
It’s because what follows after requires and is within curly braces {} is referred to as a compound requirement.
 Compound requirements can contain within them other requirements separated by a semicolon ;. 
 If the expression inside is not prefixed by the requires keyword it must only be a valid C++ statement.
  However, what follows directly after requires without the surrounding curly braces must instead evaluate
   to true at compile time. Therefore line #3 means that the value of std::integral<T> must evaluate to true. 
   If we remove requires from line #3 it would mean only that std::integral<T> is a valid C++ code without being 
   evaluated further. Similarly line #4 tells us that the sizeof(T) must be greater than or equal to sizeof(int). 
   Without the requires keyword it would only mean whether or not sizeof(T) >= sizeof(int) is a valid C++ expression.
    Line #5 means several things: a + a must be a valid expression, a + a must not throw any exceptions, 
    and the result of a + a must return type T (or a type implicitly convertible to T). Notice that a + a is surrounded by 
    curly braces that must contain only one expression without the trailing semicolon ;.

*/
template<typename T>
requires can_add<T>
T add(T a, T b)
{
    return a + b;
}
// or i could omit requires and use can_add

template<can_add T>
T add2(T a, T b)
{
    return a + b;
}

int main()
{
    std::cout << add(10, 20) << '\n';
    std::cout << add2(20, 30) << '\n';
    
    return 0;
}