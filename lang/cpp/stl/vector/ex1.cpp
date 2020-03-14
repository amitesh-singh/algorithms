#include <iostream>
#include <vector>

void print(std::vector<int> &v)
{
   for (int i = 0; i < v.size(); ++i)
     {
        std::cout << "v[" << i << "] = " << v[i] << std::endl;
     }
}

int main()
{
   std::vector<int> v;

   v.push_back(10);
   v.push_back(20);
   v.push_back(10);
   v.push_back(100);
   v.push_back(101);

   print(v);

   int head = v.front();
   int tail = v.back();
   int val = v[2];
   //or
   int val2 = v.at(2);
   std::cout << "v[2]=" << val << std::endl;
   std::cout << "head=" << head << " tail=" << tail << std::endl;

   std::cout << "removing head:\n";
   //remove head.
   v.erase(v.begin());

   print(v);
   std::cout << "deleting tail\n";
   //deleting the tail.
   v.pop_back();

   //use iterators for iterating
   for (std::vector<int>::iterator itr = v.begin();
        itr != v.end(); ++itr)
     std::cout << *itr << std::endl; //print

   //insert at head, better to do with v.push_front()?  
   // it's a heavy operation because of right shift, O(n)
   v.insert(v.begin(), -1);
   v.insert(v.begin() + 2, -5);

   print(v);

   //delete all elements.
   v.clear();

   return 0;
}
