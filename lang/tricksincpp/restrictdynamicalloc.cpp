#include <iostream>
#include <memory> // for unique_ptr
// you can use delete operator new to prevent classes 
// from being dynamically allocated.
class A
{
   int x;
  public:
      void *operator new(std::size_t) = delete;
};

int main()
{
   A aa;
   A *ptr = new A; //error
   std::unique_ptr<A> ptr2 = std::make_unique<A>(); //error
   return 0;
}
