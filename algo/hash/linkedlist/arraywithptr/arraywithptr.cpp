#include <iostream>

using namespace std;

#define MAX_NODES_SIZE 10001
#define HASH_SIZE 1001

struct node_t
{
   int data;
   int count;
   node_t *next;
};

int N;
node_t nodes[MAX_NODES_SIZE];
node_t *hash_table[HASH_SIZE];


void init()
{
   N = 0;
   for (int i = 0; i < HASH_SIZE; ++i)
     {
        hash_table[i] = nullptr;
     }
}

void add(int num)
{
   int key = num % HASH_SIZE;
   node_t *p = hash_table[key];
   
   while(p)
   {
      if (p->data == num)
         break;
      
      p = p->next;
   }

   if (p == nullptr)
   {
      nodes[N].data = num;
      nodes[N].next = hash_table[key];
      nodes[N].count = 1;

      hash_table[key] = &nodes[N];
      N++;
   }
   else
   {
      if (p->count >= 1)
         p->count++;
   }
}

void print()
{
   for (int i = 0; i < N; ++i)
   {
      cout << nodes[i].data << " count: " << nodes[i].count << endl;
   }
}

int main()
{
   add(100);
   add(100);
   add(1);
   add(2);
   add(3);
   add(1);
   
   print();

   return 0;
}
