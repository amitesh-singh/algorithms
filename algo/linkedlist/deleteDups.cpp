#include <iostream>

//delete all dups from a sorted linked list
// 1->1->2->2 
// nullptr
// 1->2->3->3->4
// 1->2->4

template<typename T>
struct listnode
{
   listnode<T> *next = nullptr;
   T val;
   listnode(const T &d): val(d)
   {
      next = nullptr;
   }
};

using node = listnode<int>;

void prepareList(node *&head, int k)
{
   if (head == nullptr)
     {
        head = new node(k);
        return;
     }
   node *p = head;
   while (p->next)
     {
        p = p->next;
     }

   p->next = new node(k);
}

void deleteList(node *&head)
{
   node *p = head;

   while (p)
     {
        node *next = p->next;
        delete p;
        p = next;
     }
}

//we need a dummy head here
node *deleteAllDups(node *&head)
{
   if (head == nullptr)
     return head;
   node *dummy = new node(head->val - 1);
   dummy->next = head;

   node *p = head;
   node *prev = dummy;

   bool deleteLastNode = false;
   while (p)
     {
        while (p->next && p->val == p->next->val)
          {
             node *next = p->next;
             delete p;
             //TODO: delete nodes
             p = next;
             deleteLastNode = true;
          }
        if (prev->next == p)
          prev = prev->next;
        else
          prev->next = p->next;

        if (deleteLastNode)
          {
             node *next2 = p->next;
             delete p;
             p = next2;
             deleteLastNode = false;
          }
        else
          p = p->next;
     }

   node *ret = dummy->next;
   delete dummy;

   return ret;
}

void print(node *head)
{
   if (head == nullptr)
     {std::cout << "[]\n"; return;}

   node *p = head;
   while (p)
     {
        std::cout << p->val << "->";
        p = p->next;
     }
   std::cout << std::endl;
}

int main()
{
   freopen("deleteDups_input.txt", "r", stdin);
   int T;
   std::cin >> T;
   for (int i = 1; i <= T; ++i)
     {
        int n;
        std::cin >> n;
        node *head = nullptr;
        for (int j = 0; j < n; ++j)
          {
             int val;
             std::cin >> val;
             prepareList(head, val);
          }
        std::cout << "input: ";
        print(head);
        node *newhead = deleteAllDups(head);
        std::cout << "output: ";
        print(newhead);

        deleteList(newhead);
        std::cout << std::endl;
     }
   return 0;
}
