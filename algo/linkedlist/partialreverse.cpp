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

    for (int i = 1; i < 2; ++i)
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
    if (curr && curr == right)
    {
        node *next = curr->next;
        curr->next = prev;
    }
    
    curr = curr ? curr : prev;

    return curr;
}
node *partialReverse(node *&head, int l, int r)
{
    if (head == nullptr) return head;
   //find left and right ptr.
   // we need prevToLeft and nextToRight ptr too
   node *curr = head;
   node *left = 0, *right = 0, *prevToLeft = 0, *nextToRight = 0;
    size_t count = 1;

   while (curr)
   {
       if (count == l)
       {
           left = curr;
           break;
       }
       count++;
       prevToLeft = curr;
       curr = curr->next;
   }

   while (curr)
   {
       if (count == r)
       {
           right = curr;
           break;
       }
       count++;
       curr = curr->next;
   }

   if (right)
    nextToRight = right->next;
    
    node *p = reverseList(left, right);
    if (prevToLeft)
        prevToLeft->next = p;
    else
        head = right;

    if (left)
        left->next = nextToRight;

    return head;
}

int main()
{
    node *head {nullptr};

    prepareList(head);
    print(head);
    node *newhead = partialReverse(head, 1, 2);
    print(newhead);
    return 0;
}

