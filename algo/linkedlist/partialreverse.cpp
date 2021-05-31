#include <iostream>

template<typename T>
struct listnode
{
    listnode<T> *next = nullptr;
    T data;

    listnode(T &&d): data(d) {}
};

using node = listnode<int>;

void prepareList(node *&head)
{
    head = new node(0);
    node *p = head;

    for (int i = 1; i < 10; ++i)
    {
        p->next = new node(std::move(i));
        p = p->next;
    }
}

void print(node *head)
{
    node *p = head;

    while (p)
    {
        std::cout << p->data << "->";
        p = p->next;
    }
    std::cout << std::endl;
}

node *reverseList(node *left, node *right)
{
    node *curr = left;
    node *prev = nullptr;
    while (curr != right)
    {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (curr == right)
    {
        node *next = curr->next;
        curr->next = prev;
    }
    return curr;
}
node *partialReverse(node *&head, int l, int r)
{
    if (head == nullptr) return head;
   //find left and right ptr.
   // we need prevToLeft and nextToRight ptr too
   node *curr = head;
   node *left = 0, *right = 0, *prevToLeft = 0, *nextToRight = 0;

   while (curr)
   {
       if (curr->data == l)
       {
           left = curr;
           break;
       }
       prevToLeft = curr;
       curr = curr->next;
   }

   while (curr)
   {
       if (curr->data == r)
       {
           right = curr;
           break;
       }
       curr = curr->next;
   }

   if (right)
    nextToRight = right->next;
    
    node *p = reverseList(left, right);

    prevToLeft->next = p;
    left->next = nextToRight;

    return head;
}

int main()
{
    node *head {nullptr};

    prepareList(head);
    print(head);
    node *newhead = partialReverse(head, 2, 5);
    print(newhead);
    return 0;
}

