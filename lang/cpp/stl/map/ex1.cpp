#include <iostream>
#include <map>
using namespace std;


int main()
{
   map<int, int> m;

   m[1] = 10;
   m[22] = 34;
   m[2] = 20;

   map<int, int>::iterator itr = m.begin();

   //Already sorted..
   for (; itr != m.end(); ++itr)
     {
        cout << itr->first << ":" << itr->second << endl;
     }

   return 0;
}
