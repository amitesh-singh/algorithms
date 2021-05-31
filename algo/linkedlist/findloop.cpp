#include <iostream>
#include <unordered_set>

template<typename T>
struct ListNode
{
   ListNode<T> *next = nullptr;
   T val;
   ListNode(T &&v): val(v) {}
};

using node = ListNode<int>;

bool hasLoop(node *head, node *&loop_node)
{
   node *p = head;
   std::unordered_set<node *> s;

   while (p)
     {
        if (s.find(p) != s.end())
          {
             loop_node = p;
             std::cout << p->val << "-> ";
             return true;
          }
        std::cout << p->val << "-> ";
        s.insert(p);
        p = p->next;
     }

   std::cout << "\n";
   return false;
}

int main()
{
   node *head = nullptr;

   head = new node(0);
   node *tmp = head;
   node *oldnode;
   for (int i = 1; i < 10; ++i)
     {
        tmp->next = new node(std::move(i));
        if (i == 5)
          oldnode = tmp->next;
        tmp = tmp->next;
     }
   tmp->next = oldnode;

   node *loop_node = nullptr;
   bool foundLoop = hasLoop(head, loop_node);
   if (foundLoop)
     {
        std::cout << "found loop at " << loop_node->val << std::endl;
     }

   return 0;
}
