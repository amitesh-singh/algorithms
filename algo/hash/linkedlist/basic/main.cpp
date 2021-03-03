#include <iostream>
using namespace std;
//hashing with chaining for integets
// insert(0), insert (100)

#define HASH_SIZE 1001
struct node
{
    int data;
    node *next;
    node *prev;

    node(int _d):data(_d), next(nullptr), prev(nullptr) {}
};

node *chain[HASH_SIZE];

void init()
{
    int i = 0;
    for (; i < HASH_SIZE; ++i)
        chain[i] = nullptr;
}

void insert(int val)
{
    unsigned int key = val % HASH_SIZE;
    node *newnode = new node(val);
    if (chain[key] == nullptr)
    {
        chain[key] = newnode;
    }
    else //collision
    {
        node *tmp = chain[key];
        while (tmp->next)
        {
            tmp = tmp->next;
        }

        tmp->next = newnode;
        tmp->next->prev = tmp;
    }
}

void print()
{
    unsigned int i = 0;
    for (; i < HASH_SIZE; ++i)
    {
        if (chain[i])
        {
            cout << i << ": ->" << chain[i]->data;

            node *temp = chain[i]->next;
            while (temp)
            {
                cout << "-> " << temp->data;
                temp = temp->next;
            }
            cout << "\n";
        }
    }    
}

bool search(int val)
{
    unsigned int key = val % HASH_SIZE;

    if (chain[key])
    {
        node *tmp = chain[key];
        while (tmp)
        {
            if (tmp->data == val)
                return true;
            tmp = tmp->next;
        }
    }

    return false;
}

void del(int val)
{
    unsigned int key = val % HASH_SIZE;
    node *tmp = chain[key];
    while (tmp)
    {
        if (tmp->data == val)
        {
            cout << "found\n";
            break;
        }

        tmp = tmp->next;

    }
    node *tmp2 = tmp;
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    if(!tmp->prev && !tmp->next) chain[key] = nullptr;
    delete tmp2;
    
}

int main()
{
    init();

    insert(100);
    insert(200);
    insert(1000);
    insert(1);
    insert(0);
    insert(1001);

    print();

    cout << "searching for 1001" << (search(1001) ? "found" : "not found") << endl;

    del(100);

    print();

    del(1001);

    print();

    
    return 0;
}