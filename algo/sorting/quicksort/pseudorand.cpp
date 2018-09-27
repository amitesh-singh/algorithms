#include <iostream>
using namespace std;

static unsigned long long seed = 1;

void _srand(unsigned long long s)
{
   seed = s;
}

int _rand()
{
   seed = seed * 13242435 + 12345;
   return((seed/65530) % 32768);
}


int main()
{
  // srand(101);

   for (int i = 0; i < 1000; ++i)
     {
        cout << _rand() << endl;
     }
   return 0;
}
