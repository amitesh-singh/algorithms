#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
   //by default, uses deque
   // stack<int, deque<int> > s; == stack<int> s;
   stack<int> s;

   s.push(10);
   // 10
   s.push(20);
   // 10, 20 <-- (top)
   s.push(40);
   // 10, 20, 40 <--- top

   //print backwards
   while (s.size())
     {
        cout << s.top() << ",";
        s.pop();
     }
   cout << endl;

   stack<int, vector<int> > sv; //use vector instead of deque
   s.push(10);
   // 10
   s.push(20);
   // 10, 20 <-- (top)
   s.push(40);
   while (s.size())
     {
        cout << s.top() << ",";
        s.pop();
     }
   cout << "used vector instead of deque";
   cout << endl;

   return 0;
}
