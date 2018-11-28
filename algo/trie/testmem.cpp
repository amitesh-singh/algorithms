#include <iostream>

using namespace std;

//int mempool[10];
int index = 0;
char mempool[10];

int main()
{
   int *p1 = new (mempool + index++) int;
   int *p2 = new (mempool + index++) int;

   cout << p1 << ": " << p2 << endl;

   return 0;
}
