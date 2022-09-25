#include <iostream>

template<typename... T>
auto do_stuff(T... t)
{
    //the below line is equivalent to
    // return t0 + t1 + t2 + .... + tn;
    return (t + ...); ///this is called fold expression
    //return (t + 3 + ...) will result into error, check the do_stuff_lambda
}

template<typename... T>
auto do_stuff_lambda(T... t)
{
    return ([t]() { return t + 3;}() + ...);
}
int main()
{
    std::cout << do_stuff(1, 2, 3, 4) << '\n';
    std::cout << do_stuff_lambda(1, 2, 3, 4, 5) << '\n';

    return 0;
}