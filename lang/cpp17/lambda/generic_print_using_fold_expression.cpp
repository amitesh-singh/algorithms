

#include <iostream>

void notify_one(int x)
{
    std::cout << x << std::endl;
}
int main()
{
    auto notify = [](auto&&... arg) {
         (notify_one(std::forward<decltype(arg)>(arg)), ...);
    };

    notify(1, 2, 3);
}
