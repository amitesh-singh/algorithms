#include <iostream>
#include <algorithm>
#include <iterator>

void insertElementInSortedArray(int a[], int n, int k)
{
   int i = n - 1;
   for (; k < a[i] && i >= 0; i--)
     {
        a[i+1] = a[i];
     }

   a[i+1] = k;
}

void printArr(int a[], int n)
{
   std::copy(a, a + n, std::ostream_iterator<int>(std::cout, ", "));
   std::cout << std::endl;
}

int main()
{
   int a[20] {0, 2, 34, 45, 22, -1, 23};
   int aSize = 7;
   int capacity = 20;

   std::sort(a, a + aSize);
   printArr(a, aSize);

   insertElementInSortedArray(a, aSize, 4);
   aSize++;
   printArr(a, aSize);


   //find lower bound?

   return 0;
}
