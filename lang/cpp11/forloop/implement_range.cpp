#include <iostream>
#include <vector>

//implement range based range(1, 10) which we can use it range based for loop
// for (auto i : range(1, 10)) {}

//we could just write a function which returns a container
// that container should support begin(), end()

namespace nonstd {
     std::vector<int> range(int start, int end) {
          if (start > end or end < start) throw std::runtime_error("out of bound");

          std::vector<int> v;
          for (int i = start; i <= end; ++i) {
               v.push_back(i);
          }

          return v;
     }
}

int main()
{
   try {
        for (auto x: nonstd::range(1, 10)) {
             std::cout << x << '\n';
        }
   } catch (const std::exception &e) {
        std::cout << e.what() << '\n';
   }
   return 0;
}
