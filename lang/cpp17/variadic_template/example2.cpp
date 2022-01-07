#include <iostream>
#include <functional>

template<class T>
struct Callback;

//in C++
template<typename Ret, typename... Args>
struct Callback<Ret(Args...)>
{
   static auto callback(Args... args)
     {
        return func(args...);
     }
   static std::function<Ret(Args...)> func;
};

template<typename Ret, typename... Args>
std::function<Ret(Args...)> Callback<Ret(Args...)>::func;

extern "C" void c_register_cb(void (*func)(int, int))
{
   int x = 0, y = -1;
   func(x, y);
}

typedef void (*cb)(int, int);

class A
{
   int a = 1;
  public:
   void my_cb(int x, int y)
     {
        a =2;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
     }
   A()
     {
        Callback<void(int, int)>::func = std::bind(&A::my_cb, this, std::placeholders::_1, std::placeholders::_2);
        c_register_cb(static_cast<cb>(Callback<void(int, int)>::callback));
     }
};

int main()
{
   A a;
   return 0;
}
