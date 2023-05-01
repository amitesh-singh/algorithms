#include <list>
#include <iostream>

int main()
{
   auto printList = [](auto&& l) {
        for (const auto &e: l) {
             std::cout << e << ',';
        }
        std::cout << '\n';
   };
   std::list<int> l { 1, 2, 3 ,4 };
   printList(l);

   auto itr_beg = std::begin(l);

   std::cout << "begin: " << *itr_beg << std::endl;
   //itr += 2; won't compile
   std::advance(itr_beg, 2);
   std::cout << "begin + 2: " << *itr_beg << std::endl;

   return 0;
}
