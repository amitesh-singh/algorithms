#include <iostream>
#include <type_traits>

using namespace std;

#define F cout << __PRETTY_FUNCTION__ << endl

void foo(int x)
{
   F;
}

void foo(char *x)
{
   F;
}

int main()
{
   int *p = 0; // ok

   int *ptr = nullptr;

   cout << p << " nullptr: " << ptr << endl;
   if (std::is_same<decltype(NULL), decltype(0)>::value)
     cout << "NULL == 0" << endl;
   if (std::is_same<decltype(NULL), decltype((void *)0)>::value)
     cout << "NULL == (void *)0" << endl;
   if (std::is_same<decltype(NULL), std::nullptr_t>::value)
     cout << "NULL == nullptr_t" << endl;
   if (std::is_same<decltype(nullptr), std::nullptr_t>::value)
     cout << "nullptr is of nullptr_t type" << endl;

  // foo(NULL); //compilation error, ambiguous call..
   foo(0);
   foo(nullptr);
   return 0;
}
