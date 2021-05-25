#include <iostream>

template<typename T>
struct ListNode
{
    T data;
    ListNode<T> *next = nullptr;
    ListNode(const int &d): data(d) {}
};
using node = ListNode<int>;

void makeSortedList(node *&head)
{
    if (head == nullptr)
    {
        head = new node(0);
    }

    node *p = head;


    for (int i = 1; i < 10; ++i)
    {
        p->next = new node(i);
        p = p->next;
    }
}

void printlist(node *head)
{
    node *p = head;
    while (p)
    {
        std::cout << p->data <<"=> ";
        p = p->next;
    }
    std::cout << std::endl;
}


node *getMid(node *start, node *end)
{
    if (start == nullptr) return nullptr;
    node *slow, *fast;
    slow = start;
    fast = start->next;

    while (fast != end)
    {
        fast = fast->next;
        if (fast != end)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

node *bsearch(node *start, node *end, int d)
{
    if (start == nullptr) return nullptr;

    //find mid
    node *mid = getMid(start, end);
    if (mid == nullptr) return nullptr;
    if (d < mid->data)
    {
       return bsearch(start, mid, d);
    }
    else if (d > mid->data)
    {
        return bsearch(mid->next, end, d);
    }
    else return mid;

    return nullptr; 
}


int main()
{
    node *head {nullptr};
    makeSortedList(head);
    printlist(head);

    node *tmp = bsearch(head, nullptr, 5);
    if (tmp)
        std::cout << tmp->data << " found!\n";
    return 0;
}