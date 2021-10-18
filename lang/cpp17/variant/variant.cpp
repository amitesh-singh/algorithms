#include <iostream>
#include <variant>
#include <cassert>

int main()
{
   std::variant<int, float> v, w;

   v = 43;

   int i = std::get<int>(v);
   assert(i == 43);

   w = std::get<int>(v);
   w = std::get<0>(v); //same effect as previous line
   w = v; //same effect as previous line.

   try
     {
        std::get<float>(w); //w containts int, not float: will throw
     }
   catch (const std::bad_variant_access &ex)
     {
        std::cout << ex.what() << '\n';
     }

   std::variant<std::string> x("abc");
   x = "def";

   using namespace std::literals;

   std::variant<std::string, void const *> y ("abc");
   //casts to void const * when passed a char const *
   assert(std::holds_alternative<void const *>(y)); //succeeds
   y = "xyz"s;
   assert(std::holds_alternative<std::string>(y)); //succeeds

   return 0;
}
