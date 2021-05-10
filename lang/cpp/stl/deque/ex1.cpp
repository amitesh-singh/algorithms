#include <iostream>
#include <deque>

using namespace std;

void print(deque<int> &d)
{
   deque<int>::iterator itr = d.begin();

   for (; itr != d.end(); ++itr)
     std::cout << *itr << ", ";

   std::cout << "\n";
}

void print2(deque<int> &d)
{
   for (auto i: d)
      std::cout << i << ", ";
   std::cout << std::endl;
}

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

   cout << "Head:" << d.front() << endl; //head = 40
   cout << "Tail:" << d.back() << endl; // tail = 100
   cout << "d[2] = " << d.at(2) << endl; // value at index = 2
   //insert at some index
   d.insert(d.begin() + 2, -5);

   print(d);

   std::cout << "deleting at back and front()\n";
   d.pop_back(); //remove 100
   d.pop_front(); // remove 40

   print(d);

   std::cout << "deleting at index 2\n";
   d.erase(d.begin() + 2);

   print(d);
   
   print2(d);

   //clear
   d.clear();
   return 0;
}
