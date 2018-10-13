#include <iostream>
#include <cstring>

using namespace std;

// implements hash like ["AFDD"] = 20;
enum 
{
  EMPTY,
  FILL
};

enum
{
   ADD = 100,
   MOD = 200,
   DEL = 300,
   GET_VAL = 400
};

#define HASHTABLESIZE 1001

unsigned long hashfunc(char *str)
{
   unsigned long hashVal = 5381;
   int c;

   while ((c = *str++))
     hashVal = (hashVal << 5) + hashVal + c;

   return hashVal;
}

int hashmod(unsigned long key)
{
   return key % HASHTABLESIZE;
}

struct hashtable
{
   char keyhash[50] = {0};
   int valhash = {0};
   int statushash =  {0};
};

hashtable hashTable[HASHTABLESIZE*5];

int getIndex(int initialIndex)
{
   int finalIndex = initialIndex;

   while (hashTable[finalIndex].statushash == FILL)
     {
        //linear probe
        finalIndex = (finalIndex + 1) % HASHTABLESIZE;
        if (finalIndex == initialIndex)
          {
             cerr << "Table is full\n" << endl;
          }
     }

   return finalIndex;
}

void insert(char *key, int element)
{
   int index = hashmod(hashfunc(key));

   int finalIndex = getIndex(index);

   hashTable[finalIndex].statushash = FILL;
   hashTable[finalIndex].valhash = element;
   strcpy(hashTable[finalIndex].keyhash, key);
}

int search(char *key)
{
   int index = hashmod(hashfunc(key));

   int finalIndex = index;

   while (hashTable[finalIndex].statushash == FILL)
     {
        if (!strcmp(hashTable[finalIndex].keyhash, key))
          {
             break;
          }

        finalIndex = (finalIndex + 1) % HASHTABLESIZE;
        if (finalIndex == index)
          {
             cerr << "Not found" << endl;
             return -1;
          }
     }

   return finalIndex;
}

void mod(char *key, int n)
{
   int index = search(key);

   if (index == -1)
     return;
   hashTable[index].valhash = n;
   strcpy(hashTable[index].keyhash, key);
}

int get(char *key)
{
   int index = search(key);

   if (index == -1)
     return 0;

   return hashTable[index].valhash;
}

void del(char *key)
{
   int index = search(key);

   if (index == -1)
     return;
   hashTable[index].statushash = EMPTY; //empty it
}

void dumpHash()
{
   for (int i = 0; i <= 1000; ++i)
     {
        if (hashTable[i].statushash == FILL)
          {
             cout << hashTable[i].keyhash << "=" << hashTable[i].valhash << endl;
          }
     }
}

int main()
{
   freopen("input.txt", "r", stdin);
   int T;
   cin >> T;
   int N;
   int n;
   char key[13];
   int command;
   int val;

   for (int t = 1; t <= T; ++t)
     {
        cin >> N;
        for (int i = 0; i < N; ++i)
          {
             cin >> command;

             switch(command)
               {
                case ADD:
                   cin >> key;
                   cin >> n;
                   insert(key, n);
                   break;

                case MOD:
                   cin >> key;
                   cin >> n;
                   mod(key, n);
                   break;

                case DEL:
                   cin >> key;
                   del(key);
                   break;

                case GET_VAL:
                   cin >> key;
                   val = get(key);
                   cout << val << endl;
                   break;

                default:
                   ;
               }

          }
        dumpHash();
     }

   return 0;
}
