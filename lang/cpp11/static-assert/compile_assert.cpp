#include <iostream>

using namespace std;

/*
   C++03 provides an assert macro that allows testing for assertions at runtime. However, for templated programming, it’s sometimes useful to be able to test assertions at compile type. C++11 provides a new keyword called static_assert that does a compile-time assertion test.

   Note that because static_assert is checked at compile time, it can not be used to evaluate assumptions that depend on runtime values. Static_asserts is primarily useful for checking the size of things via sizeof() or determining that #defined values are within certain boundaries.
 */

int main()
{
   // compile time assert.
   static_assert(sizeof(int) > 4, "int needs to be size of 4 to use this code");

   return 0;
}
