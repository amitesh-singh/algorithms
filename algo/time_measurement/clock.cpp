#include <iostream>
#include <ctime>

using namespace std;

int main()
{
   clock_t t1, t2; //or long
   t1 = clock();

   for (int i = 0; i < 1000; ++i) ++i;

   t2 = clock();

   cout << "time: " << t2 - t1 << " ms" << endl;

   return 0;
}
