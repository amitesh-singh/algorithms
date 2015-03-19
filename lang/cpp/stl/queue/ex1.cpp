#include <iostream>
#include <queue>

using namespace std;

int main()
{
   //FIFO
   // insert element into back
   // remove element from front
   queue<int> q;

   // front ->10 <-- back
   q.push(10);
   // front --> 10, 200 --> back
   q.push(200);
   q.push(11);
   q.push(243);
   // 10, 200, 11, 243 
   //q.front() -> 10
   //q.back() -> 243

   while (!q.empty())
     {
        cout << q.front() << ",";
        q.pop();
     }
   cout << endl;

   return 0;
}
