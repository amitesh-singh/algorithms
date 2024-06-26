#include <iostream>
#include <vector>
#include <sstream>

//fold expression removes the need of using recursion 
/*
e.g.
earlier we used to do following to implement sum

template<typename T>
T sum(T a)
{
    return a;
}

template<typename T, typename... Args>
auto sum(T first, T second, Args&&... args)
{
    return first + sum(args...);
}



https://www.scs.stanford.edu/~dm/blog/param-pack.html

There are four types of fold in C++. In these examples, let pat be a cast-expression containing one more 
more unexpanded parameter packs (i.e., a pattern). Let e be a normal cast-expression without any unexpanded parameter packs. 
Let p1, …, pn be the instances of pat corresponding to each element captured by pat’s unexpanded parameter packs. 
Let ⊕ stand for any binary operator in the C++ grammar (.*, ->*, *, /, %, +, -, <<, >>, <=>, <, <=, >, >=, ==, 
!=, &, ^, |, &&, ||, =, +=, -=, *=, /=, %=, <<=, >>=, &=, ^=, |=, or the comma operator “,”).

A binary left fold has the form (e⊕...⊕pat) and is equivalent to (((e ⊕ p1) ⊕ p2) ⊕ ⋯) ⊕ pn.

A unary left fold has the form (...⊕pat) and is equivalent to ((p1 ⊕ p2) ⊕ ⋯) ⊕ pn.

A binary right fold has the form (pat⊕...⊕e) and is equivalent to p1⊕(p2⊕(⋯⊕(pn⊕e))).

A unary right fold has the form (pat⊕...) and is equivalent to p1⊕(p2⊕(⋯ ⊕ pn)).

Note that parentheses are always required around a fold, regardless of context.

When the parameter pack is empty (has size 0), a binary fold is equivalent to e. A unary fold over an empty parameter pack is only permitted for 3 specific binary operators:

If ⊕ is &&, then an empty unary fold is equivalent to true.
If ⊕ is ||, then an empty unary fold is equivalent to false.
If ⊕ is the comma operator ,, then an empty unary fold is equivalent to void().


*/
//refer to https://www.fluentcpp.com/2021/03/12/cpp-fold-expressions/
template<typename... T>
auto do_stuff(T... t)
{
    //the below line is equivalent to
    // return t0 + (t1 + (t2 + .... (tn-1 + tn))...;
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

//A way to remember it is that the associativity is on the same side as the dot dot dot.
template<typename... T>
auto sum2(T&&... args)
{
    //arg1 + (arg2 + arg3)
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

auto sum3(auto&&... pack)
{
    return (... + pack);
}

auto avg(auto&&... pack)
{
    auto s = sum3(pack...);
    return s/sizeof...(pack);
}

auto version(auto&&... pack)
{
    return (... + [pack](){ return "." + pack;}());
    //return ([pack](){ return pack + ".";}() + ...);
}

std::string version2(auto&&... args) {
    std::stringstream result;
    auto concat_with_period = [&result](auto&& arg) {
        if (result.tellp() != 0) {
            result << ".";
        }
        result << std::forward<decltype(arg)>(arg);
    };

    (..., concat_with_period(std::forward<decltype(args)>(args)));

    return result.str();
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

    std::cout << "average: " << avg(10, 11.0, 2) << std::endl;


    s1 = "1"; 
    s2 = "2";
    std::string res = version(s1, s2);
    std::cout << "version(1, 2): " << res << std::endl;
    res = version2(s1, s2);
    std::cout << "version2(1, 2): " << res << std::endl;
    return 0;
}
