#include <iostream>
#include <vector>


template<typename T>
struct node
{
    T data;
    node *next = nullptr;

    node(T d, node *n) : data(d), next(n) {}
    node() = default; 
};

template<typename T>
class persistent_list
{
    node<T> *head = nullptr;
    persistent_list(node<T> const *t): head(t) {}

    public:
    persistent_list() {}
    persistent_list(T val, persistent_list *l): head(new node(val, l->head)) {}
    bool isEmpty() const { return !head;}

    persistent_list pop_front() const
    {
        if (isEmpty()) return nullptr;
        return persistent_list(head->next);
    }

    persistent_list push_front(T d)
    {
        return persistent_list(d, this);
    }

    void push(T d)
    {
        if (isEmpty()) { head = new node(d); return;}
        //better to have tail.
        node *p = head;
        while (p->next)
            p = p->next;
        
        p->next = new node(d);
    }

    void pop()
    {
        if (isEmpty()) return;
        node *tmp = head;
        head = head->next;
        delete tmp;
    }
};

int main()
{
    std::vector<persistent_list<int>> versions;
    int version_idx = 0;

    persistent_list<int> plist;
    plist.push(11);
    plist.push(12);

    versions.push_back(plist.push_front(20));
    versions.push_back(plist.push_front(211));
    return 0;
}