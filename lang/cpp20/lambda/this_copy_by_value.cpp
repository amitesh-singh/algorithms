#include <iostream>

class A
{
   int x = 0;
  public:
      void run()
        {
           auto l = [*this]() {
                std::cout << x << std::endl;
           };
           x = 43;
           l();
        }
};

int main()
{
   A aa;
   aa.run();
   aa.run();

   return 0;
}
