#include <iostream>
#include <variant>
#include <vector>

int main()
{

   std::vector<std::variant<char, long, float, int, double, long long>>
       vecVariant = {'a', 4l, 5.4, 4, 3.5, 2017ll};

   for (auto &v : vecVariant)
     std::visit([](auto arg) { std::cout << arg << " "; }, v);
   std::cout << '\n';

   /*
    *this won't work!!
   for (auto &v : vecVariant)
     std::cout << v << " ";
   */

   for (auto &v : vecVariant)
     std::visit([](auto arg) { std::cout << typeid(arg).name() << " "; }, v);
   std::cout << '\n';

   return 0;
}
