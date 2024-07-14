#include <iostream>

template<typename T>
struct X
{
    template<typename F, typename... Args>
    void add(F&& f, Args&&... args)
    {
        //this is how you can get the return type of a function
        using ReturnType = decltype(f(args...));
        ReturnType rt;

        std::cout << "return type: " << typeid(rt).name() << '\n';
    }

    void add2(auto&& f, auto&&... args)
    {
        using ReturnType = decltype(f(args...));
        //or 
        // decltype(f(args...)) rt;
        ReturnType rt;

        std::cout << "return type: " << typeid(rt).name() << '\n';
    }
};


int main()
{
    X<int> x;
    x.add([](int x) {
        std::cout << "calling me\n";
        return x;
    }, 10);

    x.add([](double x) {
        return x;
    }, 10.2);

    // this won't work for void, since we can't create variables of type void
   // x.add([]() {
    //     return;
    //});

    x.add2([](double x) {
        return x;
    }, 10.2);
    return 0;
}