#include <iostream>
#include <map>

using namespace std;

int main()
{
   map<int, char> map_key;
   /*{ {1, 'a'}, {2, 'b'}}; This is not allowed in C++98*/

   //C++ 98 way to initialize
   map_key[1] = 'a';
   map_key[2] = 'b';

   //Lets find 2
   map<int, char>::iterator itr_2 = map_key.find(2);

   //if it is not equal to end.. we got it. :)
   if (itr_2 != map_key.end())
     {
        cout << "itr2 " << itr_2->first << " : " << itr_2->second << endl;
     }
   return 0;
}
