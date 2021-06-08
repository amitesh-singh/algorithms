#include <functional>
#include <iostream>

void callanyfunction(std::function<void()> f)
{
   f();
}

void callme()
{
   std::cout << "call me\n";
}

void printnum(int x)
{
   std::cout << "printnum:" << x << std::endl;
}

struct functor
{
   bool operator()(int i)
     {
        std::cout << "functor: " << i << std::endl;
        return true;
     }
};

struct Foo
{
  public:
      void job()
        {
           std::cout << "Foo::job\n";
        }

      void job2(int i)
        {
           std::cout << "Foo: job2: " << i << std::endl;
        }
};

int main()
{
   callanyfunction(callme);

   callanyfunction(std::bind(printnum, 10));

   callanyfunction(std::bind(functor(), 11));

   Foo foo;
   callanyfunction(std::bind(&Foo::job, &foo));
   callanyfunction(std::bind(&Foo::job2, &foo, 1));
   return 0;
}
