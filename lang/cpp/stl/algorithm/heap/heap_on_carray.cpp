#include <iostream>
#include <algorithm>

int main()
{
   int a[20] = {1, 2, -9, 0, 23, 9};
   int aSize = 6;

   std::make_heap(a, a + aSize);

   for (int i = 0; i < aSize; ++i)
     std::cout << a[i] << ", ";
   std::cout << std::endl;

   std::cout << "popping up top element\n";
   std::pop_heap(a, a + aSize);
   aSize--;
   for (int i = 0; i < aSize; ++i)
     std::cout << a[i] << ", ";
   std::cout << std::endl;

   std::cout << "Adding at 10 at the end of arr\n";
   a[aSize] = 10;
   aSize++;
   for (int i = 0; i < aSize; ++i)
     std::cout << a[i] << ", ";
   std::cout << std::endl;

   std::cout << "Applying push_heap\n";
   std::push_heap(a, a + aSize);
   for (int i = 0; i < aSize; ++i)
     std::cout << a[i] << ", ";
   std::cout << std::endl;

   return 0;
}
