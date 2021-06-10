#include <iostream>

template<typename T>
struct listnode
{
    T data;
    listnode<T> *next {nullptr};
    listnode(const T &d): data(d) {}
};

using node = listnode<int>;
node *merge(node *left, node *right)
{
    node *result {nullptr};
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

//iterative
node *merge2(node *left, node *right)
{
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    node dummy(0);
    node *result = &dummy;
    
    while (left && right)
    {
        if (left->data <= right->data)
        {
            result->next = left;
            left = left->next;
        }
        else
        {
            result->next = right;
            right = right->next;
        }

        result = result->next;
    }
    if (left) result->next = left;
    else
        result->next = right;
        
    return dummy.next;
}

node *mergesort(node *&head)
{
    if (head == nullptr || head->next == nullptr) return head;

    //get the mid
    node *slow = head;
    node *fast = head;
    node *prev = nullptr;
    while (slow && fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    //slow -> mid
    prev->next = nullptr;

    node *left_side = mergesort(head);
    node *right_side = mergesort(slow);

    return merge2(left_side, right_side);
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
int main()
{
    node *head = nullptr;
    for (int i =0; i < 10; ++i)
    {
        if (head == nullptr)
        {
            head = new node(2*i + 2);
            continue;
        }

        node *p = head;
        while (p->next)
            p = p->next;
        p->next = new node(i);

    }

    print(head);

    head = mergesort(head);

    print(head);
    
    return 0;
}