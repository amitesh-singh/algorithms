#include <iostream>
#include <functional>
#include <memory>

int add (int i, int j, int k)
{
    return i + j + k;
}

namespace nonstd
{
    template<typename Func, typename... Args>
    auto bind_front(Func&& func, Args&&... args)
    {
        //return [&](auto&& ) <-- this did not work
        return [func=std::forward<Func>(func),
                ...args=std::forward<Args>(args)]
                (auto&&... param) mutable ->decltype(auto)  {
            return std::invoke(func, args...,
                        std::forward<decltype(param)>(param)...);
        };
    }

    template<typename Func, typename... Args>
    auto bind_front2(Func &&func, Args&&... args)
    {
        return [&func, ...args = std::forward<Args>(args)](auto&&... param)->decltype(auto)  {
            return std::invoke(std::forward<Func>(func), args..., std::forward<decltype(param)>(param)...);
        };
    }

    template<typename Func, typename... Args>
    auto bind_front3(Func &&func, Args&&... args)
    {
        return [&](auto&&... param)->decltype(auto)  {
            return std::invoke(std::forward<Func>(func), std::forward<Args>(args)..., std::forward<decltype(param)>(param)...);
        };
    }
    
}

class A
{
    int a { 0};
    public:
    void update()
    {
        a++;
    }
    int get_a()
    {
        return a;
    }
};
int main(int argc, char **Argv)
{
    auto func = std::bind_front(&add, 1, 2);
    std::cout << func(3) << std::endl;

    auto func2 = nonstd::bind_front(&add, 1, 2);
    std::cout << func2(3) << std::endl;

    auto func3 = nonstd::bind_front3(&add, 1, 2);
    std::cout << func3(3) << std::endl;
    //func2(3);
    A aa;
    auto func4 = nonstd::bind_front(&A::update, std::ref(aa));
    func4();
    func4();
    func4();
    std::cout << aa.get_a() << std::endl;

    A bb;
    auto func5 = nonstd::bind_front3(&A::update, &bb);

    func5();
    A &cc = bb;
    auto func6 = nonstd::bind_front(&A::update, std::ref(cc));
    func6();
    std::cout << bb.get_a() << std::endl;

    std::shared_ptr<A> a_ptr = std::make_shared<A>();
    auto func7 = nonstd::bind_front(&A::update, a_ptr);

    func7();
    std::cout << a_ptr->get_a() << std::endl;

    return 0;
}