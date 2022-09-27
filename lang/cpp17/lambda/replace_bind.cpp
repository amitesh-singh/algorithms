#include <iostream>
#include <functional>

void dispatch(std::function<void()> f)
{
   std::cout << "dispatching..\n";
   f();
}

void dispatch2(int x, int y)
{
   std::cout << x << y << '\n';
}

template<typename T1, typename... Args>
void dispatch(T1 &&func, Args... args)
{
   dispatch(std::bind(std::forward<T1>(func), std::forward<Args>(args)...));
}

int main()
{
   dispatch(std::bind(dispatch2, 10, 11));
   dispatch([]() { dispatch2(10, 11); });

   dispatch(dispatch2, 1, 2);

   return 0;
}
