//
//
//  1 -> 2 -> 3 -> 4->4->5->14->null
//  it has one random ptr which points to a random node.
//  e.g. 1 pointing to 4 and 2 pointing  to 3 etc
//  create a clone of this type node.
//
// LeetCode: https://leetcode.com/problems/copy-list-with-random-pointer/

#include <iostream>

template<typename T>
struct listnode
{
   T data;
   listnode<T> *next = nullptr;
   listnode<T> *random = nullptr;
   listnode(const T &d): data(d) {}
};

#include <vector>

template<typename T>
class list
{
   using node = listnode<T>;
   node *head = nullptr;
   node *tail = nullptr;
   std::vector<node *> v;

  public:
   void push_back(const T &d)
     {
        if (tail == nullptr)
          {
             //so that we get nullptr too in randomness
             v.push_back(nullptr);
             head = tail = new node(d);
             v.push_back(head);
             return;
          }
        node *tmp = new node(d);
        tail->next = tmp;
        tail = tmp;
        v.push_back(tmp);
     }

   void print()
     {
        node *p = head;
        while (p)
          {
             std::cout << p->data << " ";
             p = p->next;
          }
        std::cout << std::endl;
     }
};


int main()
{
   list<int> l;
   for (int i = 0; i < 10; ++i)
     l.push_back(i);

   l.print();
   return 0;
}
