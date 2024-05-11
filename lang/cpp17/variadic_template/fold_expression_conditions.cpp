#include <iostream>

// This is handy when we want to pass a conditional statement in a templated code.

template<int x = 10>
class A
{
    public:
    bool is_equal(auto&&... conditions)
    {
        bool ret = ((x == conditions) || ...);

        std::cout << "ret: " << ret << std::endl;
        return ret;
    }
};

int main()
{
    A<10> aa;

    aa.is_equal(10, 20);

    aa.is_equal(20, 30, 20, 2);

    return 0;
}