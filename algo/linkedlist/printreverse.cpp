#include <iostream>

template<typename T>
struct node
{
    T data;
    node<T> *next;
    node(const T &d) : data(d), next(nullptr) {}
};

template<typename nodetype, typename T = decltype(nodetype::data)>
struct list
{
    nodetype *head;
    void add(T data)
    {
        if (head == nullptr) {
            head = new nodetype(data);
            return;
        }
        nodetype *p = head;
        while (p->next)
        {
            p = p->next;
        }

        p->next = new nodetype(data);    
    }

    list(): head(nullptr) {}
    ~list()
    {
        nodetype *p = head;
        while (p)
        {
            nodetype *next = p->next;
            delete p;
            p = next;
        }
    }
    
    void print()
    {
        nodetype *p = head;
        while (p)
        {
            std::cout << p->data << ", ";
            p = p->next;
        }

        std::cout << "\n";
    }
};

node<int> *reverse(node<int> *&p)
{
    if (p == nullptr || p->next == nullptr) return p;
    auto res = reverse(p->next);
    p->next->next = p;
    p->next = nullptr;

    return res;
}

node<int> * reverse2(node<int> *&p)
{
    node<int> *curr = p;
    node<int> *prev = nullptr;
    
    while (curr)
    {
        node<int> *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void reversepartiallist(node<int> *&head, int left, int right)
{
    //traverse the list first and find the left and right ptrs
    node<int> *curr = head;
    node<int> *leftptr = nullptr;
    node<int> *rightptr = nullptr;
    while (curr)
    {
        if (curr->data == left)
        {
            leftptr = curr;
        }
        if (curr->data == right)
        {
            rightptr = curr;
        }
        curr = curr->next;
    }
}
int main()
{
    list<node<int>> l;

    for (int i = 0; i < 10; ++i)
        l.add(i++);
    l.print();
    auto newhead = reverse(l.head);
    l.head = newhead;
    l.print();
    l.head = reverse2(l.head);
    l.print();
    return 0;
}
