// 1->2->3->4
// 1->1->2->2->3->3->4->
//
#include <iostream>

template<typename T>
struct listnode
{
   listnode<T> *next {nullptr};
   T data;
   listnode(const T &d): data(d) {}
};

using node = listnode<int>;
void insert(node *&head, int x)
{
   if (head == nullptr)
     {
        head = new node(x);
        return;
     }

   node *p = head;
   while (p->next)
     {
        p = p->next;
     }
   p->next = new node(x);
}

void addDups(node *&head)
{
   if (head == nullptr) return ;

   node *p = head;
   while (p)
     {
        node *next = p->next;
        p->next = new node(p->data);
        p->next->next = next;
        p = next;
     }
}

void print(node *head)
{
   node *p = head;

   while (p)
     {
        std::cout << p->data << " ";
        p = p->next;
     }
   std::cout << std::endl;
}

void clear(node *&head)
{
   if (head == nullptr) return;
   node *p = head;

   while (p)
     {
        node *next = p->next;
        delete p;
        p = p->next;
     }
}

int main()
{
   node *head = nullptr;
   for (int i = 0; i < 10; ++i)
     insert(head, i);

   addDups(head);
   print(head);
   clear(head);
   return 0;
}
