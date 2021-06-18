#include <iostream>
#include <vector>

/*
https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md#12-vector-stdvector

Use for

Simple storage
Adding but not deleting
Serialization
Quick lookups by index
Easy conversion to C-style arrays
Efficient traversal (contiguous CPU caching)


Do not use for

Insertion/deletion in the middle of the list
Dynamically changing storage
Non-integer indexing
Time Complexity

Operation	Time Complexity
Insert Head	O(n)
Insert Index	O(n)
Insert Tail	O(1)
Remove Head	O(n)
Remove Index	O(n)
Remove Tail	O(1)
Find Index	O(1)
Find Object	O(n)
*/

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

   v.push_back(10); //insert at tail
   v.push_back(20); //insert at tail
   v.push_back(10);
   v.push_back(100);
   v.push_back(101);

   v.emplace_back(1992); // emplace_back(T &&);
   print(v);

   int head = v.front(); //head or v[0]
   int tail = v.back(); //tail or use v[v.size() - 1]
   int val = v[2]; //at index
   //or
   int val2 = v.at(2);
   std::cout << "v[2]=" << val << std::endl;
   std::cout << "head=" << head << " tail=" << tail << std::endl;

   std::cout << "removing head:\n";
   //remove head.
   v.erase(v.begin());

   print(v);
   std::cout << "deleting tail\n";
   //remove tail.
   v.pop_back();

   //use iterators for iterating
   for (std::vector<int>::iterator itr = v.begin();
        itr != v.end(); ++itr)
     std::cout << *itr << std::endl; //print

   //insert at head, better to do with v.push_front()?  
   // it's a heavy operation because of right shift, O(n)
   v.insert(v.begin(), -1); //insert at head
   v.insert(v.begin() + 2, -5); //insert at an index

   print(v);

   v.erase(v.begin()); //remove head
   v.erase(v.begin() + 2); //remove at an index
   v.pop_back(); //remove tail

   //how to find max in vector using std::max
   int maxVal = 0;
   for (auto &x: v)
      std::cout << x << "->";
   std::cout << std::endl;
   
   for (auto &x: v)
      maxVal = std::max(maxVal, x);
   std::cout << "max value: " << maxVal << std::endl;
   //delete all elements.
   v.clear();

   return 0;
}
