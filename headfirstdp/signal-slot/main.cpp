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

class light
{
  public:
      void on()
        {
           std::cout << "light is on\n";
        }
      void off()
        {
           std::cout << "light is off\n";
        }
};

class btn
{
  public:
      signal<> on;
      signal<> off;
      void upPress()
        {
           on.emit();
        }
      void downPress()
        {
           off.emit();
        }
};

int main()
{
   btn b;
   light l;
   b.on.connect(std::bind(&light::on, std::ref(l)));
   b.off.connect(std::bind(&light::off, std::ref(l)));

   b.upPress();
   b.downPress();

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

   sig.connect(std::bind(&A::f, std::ref(aa), std::placeholders::_1, std::placeholders::_2));
   sig.emit("meh", 20);

   return 0;
}
