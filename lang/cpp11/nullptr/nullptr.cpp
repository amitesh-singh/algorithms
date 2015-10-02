#include <iostream>

using namespace std;

int main()
{
   int *p = 0; // ok

   int *ptr = nullptr;

   cout << p << " nullptr: " << ptr << endl;

   return 0;
}
