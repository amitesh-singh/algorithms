#include <iostream>
#include <functional>

typedef void (*func_cb_t)(int, int);

extern "C" void my_c_register_cb(void (*func)(int, int))
{
   int x = 0, y = 0;

   func(x, y);
}
struct Callback
{
   static void callback(int x, int y)
                             {
                                func(x, y);
                             }
   static std::function<void(int, int)> func;
};

std::function<void(int, int)> Callback::func;

namespace A_placeholders
{
    auto x = std::placeholders::_1;
    auto y = std::placeholders::_2;
};

class A
{
   int a = 1;
  public:
      void cb(int x, int y)
        {
           a = 2;
           std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
      A()
        {
            Callback::func = std::bind(&A::cb, this, A_placeholders::x, A_placeholders::y);
            my_c_register_cb(static_cast<func_cb_t>(&Callback::callback));
        }
};

int main()
{
   A a;
}
