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

namespace experimental {

     class range
       {
         private:
             int last;
             int iter;

         public:
             range(int end):
                 last(end),
                 iter(0)
          {}

             // Iterable functions
             const range& begin() const { return *this; }
             const range& end() const { return *this; }

             // Iterator functions
             bool operator!=(const range&) const { return iter < last; }
             void operator++() { ++iter; }
             int operator*() const { return iter; }
       };
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

   for (auto i: experimental::range(10))
     {
        std::cout << i << std::endl;
     }

   return 0;
}
