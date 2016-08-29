#include <stdio.h>

// http://www.keil.com/support/man/docs/armcc/armcc_chr1359124983230.htm
// 
//Data marked with __attribute__((used)) is tagged in the object file to avoid removal by linker unused section removal.
//unused - This attribute, attached to a variable, means that the variable is meant to be possibly unused. GCC does not produce a warning for this variable. 
//aligned(1) : 
static const char author_name[]
__attribute__((__used__)) __attribute__ ((section(".testinfo"), unused, aligned(1))) = "Amitesh Singh";

static const char license[] __attribute__((__used__)) __attribute__ ((section(".testinfo"), unused, aligned(1))) = "GPLv2";

static const char desc[] __attribute__((__used__)) __attribute__ ((section(".testinfo"), unused, aligned(1))) = "module basic example";

int main()
{
   return 0;
}
