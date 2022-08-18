#include <iostream>
#include <optional>

int main()
{
   std::optional<bool> f;
   if (f) std::cout << *f << std::endl;
   f = true;
   if (f) std::cout << *f << std::endl;

   enum tribool: uint8_t {False = 0, True = 1, Unknown = 2 }
   t2 {tribool::Unknown};
   tribool t = tribool::False;
   return 00;
}
