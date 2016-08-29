#include <stdio.h>

#define Y(n1, n2) int n1##n2
#define X(_n) Y(n, _n) 
int main()
{
   X(rt);
   rtrt = 10;
   return 0;
}
