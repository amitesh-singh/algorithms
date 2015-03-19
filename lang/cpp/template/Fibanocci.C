#include<iostream>
typedef unsigned int uint64_t;
using namespace std;

template<unsigned int n>
class Fibbanoci
{
    public:
    static const uint64_t r = Fibbanoci<n-1>::r + Fibbanoci<n-2>::r;
};
template<>
class Fibbanoci<1>
{
    public:
    static const uint64_t r = 1;
};
template<>
class Fibbanoci<0>
{
    public:
    static const uint64_t r = 0;
};

int main()
{
    unsigned int result = Fibbanoci<10>::r ;

    cout << result << endl;
    return 0;
}
