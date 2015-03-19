#include <iostream>
#include <deque>

using namespace std;


int main()
{
   deque<int> d;

   // 10
   d.push_back(10);

   // 20, 10
   d.push_front(20);
   // 40, 20, 10
   d.push_front(40);
   // 40, 20, 10, 100
   d.push_back(100);

   cout << "Front:" << d.front() << endl;
   cout << "Back:" << d.back() << endl;

   deque<int>::iterator itr = d.begin();
   //traverse
   for (; itr != d.end(); ++itr)
     {
        cout << *itr << ",";
     }
   cout << endl;

   d.pop_back(); //remove 100
   d.pop_front(); // remove 40
   itr = d.begin();
   for (; itr != d.end(); ++itr)
     {
        cout << *itr << ",";
     }
   cout << endl;

   return 0;
}
