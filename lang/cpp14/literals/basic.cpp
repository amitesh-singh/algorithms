#include <iostream>

class distance
{
   size_t _d;
  public:
   distance(const size_t &d): _d(d) {}
   distance() = default;

   void print() {
        std::cout << "d: " << _d << '\n';
   }

   distance(distance &&) = default;
   distance &operator=(const distance &) = default;
};

namespace distance_literals {
     //string literals has to be global and better to put them inside a namespace
     distance operator""km(unsigned long long int km) {
          return std::move(distance(km));
     }
}

int main()
{

   distance d;
   using namespace distance_literals;
   d = 10km;

   d.print();
   return 0;
}

