#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randfunc()
{
  return rand();
}

int main()
{
  srand(time(nullptr));
       //init-statment; condition
   if (int i = 10; i == 10)
     cout << "it's equal to " << i << endl;
   
   if (int r = randfunc(); r % 2 == 0)
    cout << "even\n";
   else if (int r = randfunc(); r % 2 == 1)
    cout << "odd\n";

   //switch

   switch(int i = rand(); i % 2)
   {
     case 0: 
      cout << "switch: even\n";
      break;
     case 1:
      cout << "switch: odd\n";
      break;
     default:
      cout << "default:\n";
   }
   return 0;
}
