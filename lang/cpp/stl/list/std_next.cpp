#include <list>
#include<iostream>
#include <deque>
int main()
{
   auto printList = [](const std::list<int> &l)->void {
        for (const auto &element: l) {
             std::cout << element << " ";
        }
        std::cout << '\n';
   };

   std::list<int> l = {1, 2, 3, -1};
   printList(l);

   l.push_front(100); //100, 1, 2, 3, -1
   printList(l);
   l.push_back(10);   //100, 1, 2, 3, -1, 10
   printList(l);
   
   auto adj_front = std::next(l.begin(), 1);
   std::cout << "adjacent to front of list is " << *adj_front << '\n';

   auto adj_back = std::prev(l.end(), 2);
   std::cout << "adjacent to back of list is " << *adj_back << '\n';


   //note: std::queue does not have begin(), end() as it does not support traversal.
   std::deque<int> q = {1, 2, 3, -1};
   q.push_back(10);
   q.push_front(10);

   auto adj_q_front = std::next(q.begin(), 1);
   std::cout << "adjacent to front of queue is " << *adj_q_front << '\n';
   
   auto adj_q_back = std::prev(l.end(), 2);
   std::cout << "adjacent to back of queue is " << *adj_q_back << '\n';

   return 0;
}
