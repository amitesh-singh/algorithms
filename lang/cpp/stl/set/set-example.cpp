#include<iostream>
#include<set>
using namespace std;

template<class T>
class len_order
{
 public:
    bool operator()(T a,T b) const
      {
         return a.id <b.id;
      }

};

class client
{
 public:
    int id;
};

int main()
{
   //note:
   //by default: its std::less<T> 
   // e.g. set<int, std::less<int> > s;
   // or set<int> s; both statements are same.
   //now S is in decending order.
   std::set<int,std::greater<int> > S;

   S.insert(1);
   S.insert(2);
   S.insert(12);
   S.insert(0);
   for(std::set<int>::iterator itr = S.begin(); itr!=S.end(); ++itr)
     cout << *itr << endl;
   std::set<client,len_order<client> > s1;

   return 0;
}
