#include <iostream>

using namespace std;

unsigned int fib(unsigned int N)
{
   if (N == 0)
     return 1;

   unsigned int a = 1, b = 1;

   unsigned int sum = 0;

   for (unsigned int i = 3; i <= N; ++i)
     {
        sum = a + b;
        a = b;
        b = sum;
     }

   return b;
}

using namespace std;

int main()
{
   cout << "fib(2): " << fib(2) << endl;
   cout << "fib(5): " << fib(5) << endl;
   cout << "fib(10): " << fib(10) << endl;

   return 0;
}
