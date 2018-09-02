#include <iostream>
#include <cstring>

using namespace std;

// implements hash like ["AFDD"] = 20;

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

struct hashtable{
char keyhash[1001*2][50] = {0};
int valhash[1001*2] = {0};
int statushash[1001*2] =  {0};
};

hashtable hashTable;

int getIndex(int initialIndex)
{
    int finalIndex = initialIndex;

    while (hashTable.statushash[finalIndex] == 1)
    {
        finalIndex = (finalIndex + finalIndex) % HASHTABLESIZE;
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

    hashTable.statushash[finalIndex] = 1;
    hashTable.valhash[finalIndex] = element;
    strcpy(hashTable.keyhash[finalIndex], key);
}

int search(char *key)
{
    int index = hashmod(hashfunc(key));

    int finalIndex = index;

    while (hashTable.statushash[finalIndex] == 1)
    {
        if (!strcmp(hashTable.keyhash[finalIndex], key))
        {
            break;
        }
        
        finalIndex = (finalIndex + finalIndex) % HASHTABLESIZE;
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
    hashTable.valhash[index] = n;
    strcpy(hashTable.keyhash[index], key);
}

int get(char *key)
{
    int index = search(key);

    if (index == -1)
        return 0;
    
    return hashTable.valhash[index];
}

void del(char *key)
{
    int index = search(key);

    if (index == -1)
        return;
    hashTable.statushash[index] = 0; //empty it
}

void dumpHash()
{
    for (int i = 0; i <= 1000; ++i)
    {
        if (hashTable.statushash[i])
        {
            cout << hashTable.keyhash[i] << "=" << hashTable.valhash[i] << endl;
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
