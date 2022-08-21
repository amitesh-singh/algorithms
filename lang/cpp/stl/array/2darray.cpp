#include <iostream>
#include <array>

int main()
{
   //2d array, int [3][3]
   // extra brackets {} are necessary in C++17 and 20
   // the below line won't compile.
   // std::array<std::array<int, 3>, 3> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   std::array<std::array<int, 3>, 3> arr = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
   for (const auto &row: arr) {
        for (const auto &element: row) {
             std::cout << element << " ";
        }
        std::cout << '\n';
   }

   std::cout << '\n';
   using matrix = std::array<std::array<int, 2>, 3>;
   matrix m = {{{1, 2}, {4, 5}, {7, 8}}};

   for (const auto &row: m) {
        for (const auto &element: row) {
             std::cout << element << ' ';
        }
        std::cout << '\n';
   }
   return 0;
}
