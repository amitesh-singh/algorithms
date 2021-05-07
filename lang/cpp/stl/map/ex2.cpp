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

   m.erase("A");
   for (auto &x : m)
   {
      cout << x.first << ": " << x.second << "; ";
   }
   cout << endl;
   
   //count the number of element with a certain key
   unsigned int count = m.count("H");
   cout << "count for  key H: " << count << endl;

   //check if the key exists
   bool exists = (m.find("X") != m.end());
   cout << "searching for key X: " << exists << endl;
   
   return 0;
}
