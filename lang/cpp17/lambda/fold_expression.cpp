#include <iostream>
#include <vector>

//refer to https://www.fluentcpp.com/2021/03/12/cpp-fold-expressions/
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

//handle no arguments
template<typename... T>
auto sum(T&&... args)
{
    return (0 + ... + args); //0 is the initial value.. so sum() would work
}

template<typename... T>
auto sum2(T&&... args)
{
    return (args + ... + 0); // 0 is the initial value.. so sum2() would work
}

template<typename obj, typename... T>
void callmemfunc(obj &o, T&&... args)
{
    ((o.*args)(), ...);
}

class A
{
    public:
    void f1()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
    void f2()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
};

auto add_all_strings_size(auto&& ... strings)
{
    std::cout << "size of the strings: " << sizeof...(strings) << std::endl;
    return (0 + ... + strings.size());
}

int main()
{
    std::cout << do_stuff(1, 2, 3, 4) << '\n';
    std::cout << do_stuff_lambda(1, 2, 3, 4, 5) << '\n';
    std::cout << sum() << '\n';
    std::cout << sum2() << '\n';


    std::vector<int> v;
    auto push_back = [](auto &&vector, auto&& ... args)
    {
        (vector.push_back(args), ...);
    };

    push_back(v, 1, 2, 3, 4);

    for (const auto &n: v) {
        std::cout << n << ',';
    }
    std::cout << '\n';

    A aa;
    callmemfunc(aa, &A::f1, &A::f2);
    std::string s1 = "lol";
    std::string s2 = "meh";

    std::cout << add_all_strings_size(s1, s2) << '\n';

    return 0;
}