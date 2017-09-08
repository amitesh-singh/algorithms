#include <iostream>

using namespace std;
template<typename T>
T adder(T v)
{
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return v;
}

template <typename T, typename... Args>
constexpr T adder(T first, Args... args)
{
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return first + adder(args...);
}

template<typename T>
bool pair_comparer(T a, T b)
{
    return a == b;
}

template<typename T1, typename... Args>
bool pair_comparer(T1 a, T1 b, Args... args)
{
    return a == b && pair_comparer(args...);
}

int main()
{
    cout << adder(100, 200, 400);
    cout << "\n";
    string s1 = "x", s2 = "y", s3 = "z";
    cout << adder(s1, s2, s3);

    cout << pair_comparer(100, 100, 200, 200, 1.4, 1.4) << "\n";
    cout << pair_comparer(100, 101, 200, 200, 300, 200);

    return 0;
}