#include <iostream>

//A to B
//

int countBitsSwap(int a, int b)
{
   int count {0};

   for (int c = a^b; c > 0; c = (c & (c-1)))
     {
        count++;
     }

   return count;
}
int main()
{
   std::cout << countBitsSwap(1, 0) << std::endl;
   return 0;
}
