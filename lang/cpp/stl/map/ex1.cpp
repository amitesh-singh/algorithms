#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

void getMap(const std::map<int, int> &m)
{
   //this will result into compilation error since operator[] is not a const function, use at() instead
   //if (m[1] == 10)
   if (m.at(1) == 10)
     std::cout << "10 is found\n";
}

int main()
{
   //self balancing BST like red black tree is map
   map<int, int> m;

   std::unordered_map<int, int> m2;

   m[1] = 10;
   m[22] = 34;
   m[2] = 20;

   getMap(m);

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

     for (auto &[n1, n2]: m)
       cout << n1 << " :" << n2 << '\n';

   cout << "unordered_map: size: " << m2.size() <<  "\n";

   for (auto &x: m2)
      cout << x.first << ": " << x.second << endl;
 
   return 0;
}
