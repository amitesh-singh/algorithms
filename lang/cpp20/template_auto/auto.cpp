#include <iostream>

/*

//this does NOT compile.
template<auto T>
auto sum(T a, T b)
{
    return a + b;
}

*/

//special case of specialization.
template<auto N, typename T>
auto avg(T a, T b)
{
    return (a + b)/N;
}


int main()
{
    std::cout << avg<10>(20, 30) << '\n';

    return 0;
}