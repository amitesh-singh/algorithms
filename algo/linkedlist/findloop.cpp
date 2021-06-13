#include <iostream>
#include <unordered_set>
#include <ctime>
#include <unordered_map>

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

// find loop in O(1)
// 
bool hasLoop2(node *head, node *&loop_node)
{
   node *p = head;
   bool isLoop = false;
   //first detect if there is a loop
   node *slow = head, *fast = head;

   while (slow && fast && fast->next)
     {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
          {
             isLoop = true;
             break;
          }
     }
   if (!isLoop)
     {
        loop_node = nullptr;
        return false;
     }

   // find the loop node
   // reset the slow pointer to head and move both fast and slow one step
   slow = head;
   while (slow && fast)
     {
        slow = slow->next;
        fast = fast->next;
        if (slow == fast)
          {
             loop_node = slow;
             break;
          }
     }

   return true;
}

int main()
{
   std::srand(std::time(nullptr));
   node *head = nullptr;

   head = new node(0);
   node *tmp = head;
   node *oldnode;
   std::unordered_map<int,node*> hash;
   hash[head->val] = head;
   int count = 1;
   for (int i = 1; i < 10; ++i)
     {
        tmp->next = new node(std::move(i));
        hash[tmp->next->val] = tmp->next;
        tmp = tmp->next;
        count++;
     }
   tmp->next = hash[std::rand() % count];

   std::cout << '\n';
   node *loop_node = nullptr;
   bool foundLoop = hasLoop(head, loop_node);
   if (foundLoop)
     {
        std::cout << "found loop at " << loop_node->val << std::endl;
     }

   loop_node = nullptr;
   foundLoop = hasLoop2(head, loop_node);

   if (foundLoop)
     {
        std::cout << "found loop at " << loop_node->val << std::endl;
     }

   return 0;
}
