#include <iostream>
#include <map>

using namespace std;

struct A
{
   int x;
};

struct Compare
{
   bool operator() (const A &lhs, const A &rhs)
     {
        return lhs.x < rhs.x;
     }

};
int main()
{
   map<A, int, Compare> m;

   A aa;
   aa.x = 10;
   A bb;
   bb.x = 20;

   m[bb] = 20;
   m[aa] = 10;

   map<A, int, Compare>::iterator itr = m.begin();

   for (; itr != m.end(); ++itr)
     {
        cout << itr->second << endl;
     }

   return 0;
}
