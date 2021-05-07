#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;


int main()
{
   //self balancing BST like red black tree is map
   map<int, int> m;

   std::unordered_map<int, int> m2;

   m[1] = 10;
   m[22] = 34;
   m[2] = 20;

   m2[1] = 10;
   m2[22] = 34;
   m2[2] = 20;

   map<int, int>::iterator itr = m.begin();

   //Already sorted..
   for (; itr != m.end(); ++itr)
     {
        cout << itr->first << ":" << itr->second << endl;
     }

     //using auto
     for (auto &x : m)
     {
        cout << x.first << " : " << x.second << endl;
     }

   cout << "unordered_map: \n";
   for (auto &x: m2)
      cout << x.first << ": " << x.second << endl;
 
   return 0;
}
