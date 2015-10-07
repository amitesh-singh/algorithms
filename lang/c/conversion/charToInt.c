#include <stdio.h>

int main()
{
  char c;
  c = '5';
  // now you want to convert that char '5' to integer 5.
  // this trick only works for 0 - 9 
  int i = c - '0';

  printf("%c: %d\n", c, i);
  
  i = c - 48;

  printf("%c: %d\n", c, i);

  return 0;
}
