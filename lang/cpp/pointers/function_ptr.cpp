#include <iostream>
using namespace std;

#define F cout << __PRETTY_FUNCTION__ << endl

template<class From, class To>
union CC
{
   From fr;
   To to;
};

template<class From, class To>
To function_cast(From from)
{
   CC<From, To> cc;
   cc.fr = from;

   return cc.to;
}

template <typename T>
struct identity {
     typedef T type;
};

//identity<void(*)(int)>::type callback = &my_func;
typedef void (*C_funcptr)();

void C_func(C_funcptr func)
{
   func();
}

class A
{
   typedef void (A::*cpp_funcptr)();
 public:
    void Cpp_Func()
      {
         F;
      }

    void register_func()
      {
         cpp_funcptr fptr = &A::Cpp_Func;
         identity<void (A::*)()>::type callback = &A::Cpp_Func;
         C_func(function_cast<cpp_funcptr, C_func>(callback));
         //(function_cast<cpp_funcptr, C_func>(fptr));
      }
};

int main()
{
   A aa;
   aa.register_func();

   return 0;
}
