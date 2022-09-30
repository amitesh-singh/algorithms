#include <iostream>
#include <functional>

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

int main()
{
    auto func = nonstd::bind(&add, 1, 2);
    std::cout << func() << std::endl;

    return 0;
}