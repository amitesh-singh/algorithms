#include<iostream>


template<class T>
struct ListNode
{
    T data;
    ListNode<T> *next = nullptr;
    ListNode(const T&d) : data(d) {}
};


using node = ListNode<int>;

void populateList(node *&head)
{
    if (head == nullptr)
        head = new node(0);
    node *curr = head;
    for (int i = 1; i < 10; ++i)
    {
        curr->next = new node(i);
        curr = curr->next;
    }
}

void printlist(node *head)
{
    node *curr = head;
    while(curr)
    {
        std::cout << curr->data <<"=> ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

node *getMid(node *start, node *end)
{
    if (start == nullptr) return nullptr;
    node *slow, *fast;
    slow = start;
    fast = start;

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

int main()
{
    node *head {nullptr};
    populateList(head);
    printlist(head);

    node *mid = getMid(head, nullptr);
    if (mid)
        std::cout << "mid is : " << mid->data << std::endl;

    return 0;
}