#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *p = malloc(sizeof(int));

   *p = 10;
   return 0;
}
