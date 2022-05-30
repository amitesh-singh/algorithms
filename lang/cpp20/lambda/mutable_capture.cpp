#include <iostream>

using namespace std;

int main()
{
   int i = 0;
   /*
   auto foo = [i]() {
        i++; //illegal, mutable needs to be defined
   };

   foo();
   */
   auto moo = [i]() mutable {
        //we'r allowed to modify i now
        i++;
   };
   
   moo();
   return 0;
}
