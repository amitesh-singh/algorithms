#include <iostream>
using namespace std;

#define HASH_SIZE 1001
#define LINKED_LIST_SIZE 100
struct db_t
{
    bool active;
    int data;
};

db_t db[HASH_SIZE];
int dbCount;

//it stores the hash_key to db[]
    //data number;hash_size; collision linked list size, first byte stores the number of items
int hash_table[1][HASH_SIZE][LINKED_LIST_SIZE];

void init()
{
    dbCount = 0;
    for (int i = 0; i < 1; ++i)
    {
        for (int j = 0; j < HASH_SIZE;++j)
        {
            hash_table[i][j][0] = 0;
        }
    }
}

void insert(int val)
{
    int x;
    db[dbCount].active = true;
    db[dbCount].data = val;

    unsigned long key = val % HASH_SIZE;
    //no. of items in that chain
    x = hash_table[0][key][0];
    //add the item in next chain
    hash_table[0][key][x+1] = dbCount;
    hash_table[0][key][0]++;

    dbCount++;
}

bool search(int val)
{
    unsigned long key = val % HASH_SIZE;
    int n;
    //get the list of items in that key point
    n = hash_table[0][key][0];
    //cout << "n: " << n << endl;
    //let's search in this list
    for (int i = 1; i <= n ; ++i)
    {
        if (db[hash_table[0][key][i]].active == true && db[hash_table[0][key][i]].data == val)
        {
            return true; 
        }
    }

    return false;
}

int main()
{
    init();
    
    insert(100);
    insert(1);
    insert(0);

    cout << "searching for " << 100 << " :" << (search(100) ? "found" : "not found") << "\n";

    
    return 0;
}