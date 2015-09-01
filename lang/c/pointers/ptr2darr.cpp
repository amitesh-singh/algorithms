#include <stdio.h>

//refer: http://stackoverflow.com/questions/14808908/c-pointer-to-two-dimensional-array

int main()
{
   int a[2][3] = { { 1, 2, 3}, {4, 5, 6}};
   // pointer to an array of 3 integers
   int (*p)[3] = a; //remember it takes 4 or 8 bytes of memory only
   printf("size of p: %d\n", sizeof p);
   //
   //       <-p->  p points to first row and covers  full row 
   // p->   1 2 3   
   // ++p-> 4 5 6
   //

   printf("first element: %d\n", p[0][0]);
   //move to next row
   p++;
   printf("first element of 2nd row: %d\n", p[0][0]);


   //This does not work well.. on delete, double free issue?
   //How to dynamically allocate it?
   /*
   int (*dp)[3] = new int[1][3];
   dp = a;
   printf("first element: %d\n", dp[0][0]);

   delete [] dp;
   */

   //one more way to allocate dynamically.
   int (**dp2)[3] = new (int (*)[3]);
   *dp2 = a;
   printf("first element of dp2: %d\n", (*dp2)[0][0]);

   delete dp2;
   printf("\n");

   // pointer to an array of 2D integers 2*3
   int (*pp)[2][3] = &a; //It covers whole array
   printf("size of pp: %ld\n", sizeof pp);

   printf("first element: %d\n", (*pp)[0][0]);

   return 0;
}
