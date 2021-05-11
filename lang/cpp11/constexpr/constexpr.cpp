#include <iostream>

using namespace std;

#define GPIOC 1
#define GPIO13 1 << 13
/*
 difference between const and constexpr
 const double pi1 = 3.14;
 constexpr double pi2 = 3.14;
 both pi1 & pi2 are constants, meaning you can't modify them. However pi2
 is a compile-time constant. It shall be initialized at compile time.
 pi1 may be initialized at compile time or run time, depends upon compiler optimization.
 Furthermore, only pi2 can be used in a context that requires a compile time constant.

*/
class Pin
{
public:
  //const expr constructor must have empty function body
  constexpr Pin(uint16_t ddr, uint16_t port): _ddr(ddr), _port(port)
  {
  }
  uint16_t _ddr, _port;
};

constexpr double PI()
{
   return 3.14;
}

int main()
{
  Pin pin(GPIOC, GPIO13);

  cout << pin._ddr << ":" << pin._port << std::endl;

  constexpr int len = 10;
  constexpr int len_2 = len + 1;
  
  cout << PI() << endl;
  
  return 0;
}
