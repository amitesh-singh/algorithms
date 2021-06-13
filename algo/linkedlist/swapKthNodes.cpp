//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
//
#include <iostream>

template<typename T>
struct node
{
   T val;
   node<T> *next = nullptr;
   node(const T &d): val(d) {}
};

void print(node<int> *head)
{
   while (head)
     {
        std::cout << head->val << "->";
        head = head->next;
     }
   std::cout << std::endl;
}

//swap nodes from left and right
node<int> *swapnodes(node<int> *head, int k)
{
   if (head == nullptr) return nullptr;

   node<int> *left = head;
   while (left)
     {
        if (--k == 0) break;
        left = left->next;
     }
   std::cout << "kth node from beginning is: " << left->val << std::endl;

   node<int> *right = head;
   node<int> *p = left->next;
   while (p)
     {
        right = right->next;
        p = p->next;
     }

   std::cout << "kth node from end is: " << right->val << std::endl;

   if (left != right)
     std::swap(left->val, right->val);


   return head;
}

int main()
{
   node<int> *head {nullptr};

   head = new node<int>(0);
   node<int> *p = head;
   for (int i = 1; i < 10; ++i)
     {
        p->next = new node(i);
        p = p->next;
     }
   print(head);

   swapnodes(head, 2);

   print(head);
   return 0;
}
