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
        //we're allowed to modify i now
        i++;
   };
   
   moo();
   std::cout << "i: " << i << std::endl;
   return 0;
}
