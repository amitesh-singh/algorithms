#include <functional>
#include <iostream>

void callme()
{
   std::cout << "callme\n";
}

void printnum(int n)
{
   std::cout << n << std::endl;
}

struct functor
{
   void operator()(int i)
     {
        std::cout << "functor()\n";
     }
};

int main()
{
   std::function<void()> f;

   f = callme;

   f();

   std::function<void(int)> f2;

   f2 = printnum;

   f2(11);

   //bind
   f = std::bind(printnum, 10);
   f();

   //lambda
   f2 = [](int x)->void {std::cout << "lambda: " << x << "\n"; };
   f2(10);

   f2 = functor();
   f2(11);

   return 0;
}
