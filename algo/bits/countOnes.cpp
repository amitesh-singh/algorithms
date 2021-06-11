#include <iostream>

int countOnes(int n)
{
   int count = 0;

   for (int i = 31; i >=0; --i)
     {
        count += (n & (1 << i)) ? 1: 0;
     }

   return count;
}

//best way, but little tricky
int countOnes2(int n)
{
   int count = 0;

   for (int c = n; c > 0; c = (c & (c-1)))
     {
        count++;
     }

   return count;
}

int main()
{
   int n;
   std::cin >> n;
   std::cout << countOnes(n) << std::endl;
   std::cout << countOnes2(n) << std::endl;
   return 0;
}
