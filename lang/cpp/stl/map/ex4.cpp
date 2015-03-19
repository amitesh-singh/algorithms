#include <iostream>
#include <map>
using namespace std;

struct Compare
{
   //descending order..
   bool operator()(const int &lhs, const int &rhs)
     {
        return lhs > rhs;
        //Ascending order.
        //return lhs < rhs;
     }
};

int main()
{
   map<int, int, Compare> m;

   m[1] = 100;
   m[2] = 4;
   m[4] = 10;
   m[3] = 1000;

   map<int, int, Compare>::iterator itr = m.begin();

   for (; itr != m.end(); ++itr)
     {
        cout << itr->first << ":" << itr->second << endl;
     }

   return 0;
}
