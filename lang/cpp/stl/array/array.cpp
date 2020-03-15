#include <iostream>
#include <array>
#include <algorithm>

/*
 * std::array provides fixed array functionality that won’t decay when passed into a function
 */

struct house
{
   int house_no {};
   int street_no {};
   house(int hno, int sno): house_no(hno), street_no(sno) {}
};

void printarr(int *arr, size_t n)
{
   std::cout << "inside printarr() \n";
   std::cout << "arr: " << arr << std::endl;
}

int main()
{
   std::array<int, 5> a1 = {5, 6, 3, 2, 1};

   //applying sort
   std::sort(begin(a1), end(a1));

   std::cout << "a1.size() = " << a1.size() << std::endl;

   auto itr = a1.begin();
   for (; itr != a1.end(); ++itr)
     std::cout << *itr << ", ";
   std::cout << "\n";

   std::cout << "a1.front() = " << a1.front() << std::endl;
   std::cout << "a1.back() = " << a1.back() << std::endl;
   std::cout << "a1.max_size() = " << a1.max_size() << std::endl;

   std::cout << "a1.at(1) = " << a1.at(1) << std::endl;
   a1.empty()? std::cout << "a1 is empty" : std::cout << "a1 is NOT empty\n";
   //fills whole array with 2
   a1.fill(2);
   for (auto &x: a1)
     std::cout << x << ", ";
   std::cout << std::endl;

   std::array<int, 6> myarr;
   myarr = {9, 3, 32, 90, 100, -1};

   std::array<house, 3> houses =  { house{1, 20}, house{2, 40}, house(3, 405) };
   for (auto &x: houses)
     {
        std::cout << "house no: " << x.house_no << " street no: " << x.street_no << std::endl;
     }

   auto houses2 = houses; //copying
   //but only with same sizes

   //can't use raw pointers, but what if i have some C API like printarr(int *arr, size_t n)?
   // use ::data() for this
   printarr(a1.data(), a1.size());

   return 0;
}
