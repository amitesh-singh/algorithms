#include <iostream>
#include "signal.h"

class A
{
  public:
      void f(std::string s1, int i)
        {
           std::cout << "A::f()\n";
        }
};

int main()
{
   signal<std::string, int> sig;
   sig.connect([](std::string arg1, int arg2) {
               std::cout << arg1 << ":" << arg2 << "\n";
               });

   sig.emit("the answer is", 42);

   A aa;
   sig.connect([&aa](std::string arg1, int arg2) {
                    aa.f(arg1, arg2);
               });

   sig.emit("the answer is", 42);
   return 0;
}
