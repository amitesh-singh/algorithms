#include <iostream>
#include <vector>
#include <list>

#define F std::cout << __PRETTY_FUNCTION__ << std::endl

class A
{
   std::vector<int> v;
  public:
   /*
    *  C++11 binds the concept to a template, called std::initializer_list.
    *  This allows constructors and other functions to take initializer-lists as parameters:
    */
   A(const std::initializer_list<int> &v)
     {
        for (auto &x: v)
          this->v.push_back(x);
        F;
     }

   A(std::initializer_list<int> &&v)
     {
        this->v = std::move(v);
        F;
     }

   ~A()
     {
        F;
     }

   void print()
     {
        for (auto &x : v)
          std::cout << x << ", ";
        std::cout << "\n";
     }
};

int main()
{
   std::vector<int> v{1, 2, 3, 4};

   for (auto &x : v)
     std::cout << x << ", ";
   std::cout << "\n";

   std::list<char> ll {'A', 'B', 'C'};
   for (char c: ll)
     std::cout << c << ", ";
   std::cout << "\n";

   A aa = {1, 2, 3, 4}; //calls A(std::initializer_list<int> &&);
   aa.print();

   aa = { 1, 2, 3, 5}; //calls A(std::initializer<list> &&)
   aa.print();

   return 0;
}
