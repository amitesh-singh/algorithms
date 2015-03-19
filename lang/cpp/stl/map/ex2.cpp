#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
   map<string, int> m;

   m["A"] = 10;
   m["H"] = 34;
   m["X"] = 20;

   map<string, int>::iterator itr = m.begin();

   //Already sorted..
   for (; itr != m.end(); ++itr)
     {
        cout << itr->first << ":" << itr->second << endl;
     }

   return 0;
}
