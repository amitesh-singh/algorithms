#include <iostream>
#include <functional>

int add (int i, int j, int k)
{
    return i + j + k;
}

namespace nonstd
{
    template<typename Func, typename... Args>
    auto bind_front(Func&& func, Args&&... args)
    {
        return [func=std::forward<Func>(func),
                ...args=std::forward<Args>(args)]
                (auto&&... param)->decltype(auto) {
            return std::invoke(func, args...,
                        std::forward<decltype(param)>(param)...);
        };
    }
}
int main(int argc, char **Argv)
{
    auto func = std::bind_front(&add, 1, 2);
    std::cout << func(3) << std::endl;

    auto func2 = nonstd::bind_front(&add, 1, 2);
    std::cout << func2(3) << std::endl;
    //func2(3);
    return 0;
}