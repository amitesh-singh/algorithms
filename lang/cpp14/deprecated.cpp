/*
 *
 * [[deprecated]] attribute

C++14 introduces the [[deprecated]] attribute to indicate that a unit (function, class, etc) is discouraged and likely yield compilation warnings. If a reason is provided, it will be included in the warnings.

[[deprecated]]
void old_method();
[[deprecated("Use new_method instead")]]
void legacy_method();
*/

#include <iostream>
using namespace std;

[[deprecated("use newer method new_method")]]
void old_method()
{
   cout << "I am an old method\n";
}

int main()
{
   old_method();
   return 0;
}
