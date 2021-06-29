//refer https://leetcode.com/problems/copy-list-with-random-pointer/
#include <iostream>
#include <ctime>
#include <unordered_map>
#include <vector>

template<typename T>
struct listnode
{
    listnode<T> *next {nullptr};
    listnode<T> *random {nullptr};
    T data;

    listnode(const T &d) : data(d) {}
};


template<typename T>
struct list
{
    using node = listnode<T>;
    node *head = nullptr;
    node *tail = nullptr;
    //assuming that we don't delete any node.
    std::vector<node *> v;

   
    public:
        list() {}
        
        void push_back(const T &d)
        {
            if (tail == nullptr)
            {
                tail = head = new node(d);
                v.push_back(tail);
                return;
            }

            node *tmp = new node(d);
            tail->next = tmp;
            tail = tmp;
            v.push_back(tmp);
        }

        void print()
        {
            node *p = head;
            while (p)
            {
                std::cout << p ;
                if (p->random) std::cout << "(->random: " << p->random << ") " ;
                std::cout << "->";
                p = p->next;
            }
            std::cout << std::endl;
        }
    void populateRandomPtrs()
    {
        node *p = head;
        int posRand; 
        while (p)
        {
            posRand = rand() % v.size();
            p->random = v[posRand];
            p = p->next;
        }
    }

};

template<class T>
void addDups(list<T> &l)
{
    using node = listnode<T>;

    //make dups
    node *p = l.head;

    while (p)
    {
        node *next = p->next;
        p->next = new node(p->data);
        p->next->next = next;
        p = next;
    }
}
template<class T>
void copyList(list<T> &l1, list<T> &l2)
{
    using node = listnode<T>;
    
    //add dups in original list.
    addDups(l1);
    l1.print();

    node *p = l1.head;
    //set the relationship of random ptrs
    while (p && p->next)
    {
        p->next->random = p->random->next;
        p = p->next->next;
    }
    l1.print();
    //now we need to separate the lists into two parts

    p = l1.head;
    l2.head = p->next;
    node *prev1 {nullptr};
    node *prev2 {nullptr};
    while (p && p->next)
    {
        if (prev1 == nullptr && prev2 == nullptr)
           {    prev1 = p;
                prev2 = p->next;
                p = p->next->next;
                continue;
           }
        std::cout << p->data << ": "<< p->next->data << std::endl;
        prev1->next = p;
        prev2->next = p->next;
        prev1 = prev1->next;
        prev2 = prev2->next;
        p = p->next->next;
    }
    
    prev1->next = nullptr;
    
    std::cout << "final copy: \n";
    l2.print();

    std::cout << "original copy: \n";
    l1.print();
}

/**
 *  using dummy head nodes
 *  Node *separateList(Node *&head)
    {
        Node dummy1(0), dummy2(0);
        
        Node *p = head;
        Node *prev1 = &dummy1, *prev2 = &dummy2;
        while (p and p->next)
        {
            prev1->next = p;
            prev2->next = p->next;
            
            prev1 = prev1->next;
            prev2 = prev2->next;
            p = p->next->next;
        }
        prev1->next = nullptr;
        return dummy2.next;
    }

    */

int main()
{
    list<int> l;
    for (int i = 0; i <10; ++i)
        l.push_back(i);
    
    l.populateRandomPtrs();

    l.print();
    
    list<int> l2;
    copyList<int>(l, l2);

    return 0;
}