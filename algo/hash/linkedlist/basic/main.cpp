#include <iostream>
using namespace std;
//hashing with chaining for integets
// insert(0), insert (100)

#define HASH_SIZE 1001
struct node
{
    int data;
    node *next;

    node(int _d):data(_d), next(nullptr) {}
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
    return 0;
}