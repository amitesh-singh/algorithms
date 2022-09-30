#include <iostream>
#include <functional>
#include <string>

namespace nonstd
{

    template<typename Func, typename... Args>
    auto bind(Func&& func, Args&&... args)
    {
        return [func=std::forward<Func>(func), ...args=std::forward<Args>(args)]()->decltype(auto) {
            return std::invoke(func, args...);
        };
    }
}
int add(int i, int j)
{
    return i + j;
}

 struct A
{
    int a {0};

    void update()
    {
        ++a;
    }

};
int main()
{
    auto func = nonstd::bind(&add, 1, 2);
    std::cout << func() << std::endl;

    std::string s("hey");
    auto func2 = std::bind(&std::string::size, s);
    std::cout << func2() << std::endl;

    A aa;
    auto func3 = std::bind(&A::update, aa);
    func3();
    std::cout << aa.a << std::endl;

    return 0;
}