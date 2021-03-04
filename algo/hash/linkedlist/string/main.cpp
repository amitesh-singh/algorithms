#include <iostream>
#include <cstring>

using namespace std;

#define LEN 20
#define TABLE_SIZE 5001
#define FIELD_SIZE 2
#define LIST_SIZE 100

enum field
{
    NAME,
    EMAIL
};

struct result 
{
    int count;
    char str[5][LEN];
    result(): count(0) {}
};

struct db_t
{
    bool active;
    char str[FIELD_SIZE][LEN];
};


int dbCount;
db_t db[TABLE_SIZE];

unsigned int hash_table[FIELD_SIZE][TABLE_SIZE][LIST_SIZE];


unsigned long hash_func(char *str)
{
    unsigned long long val = 5381;
    char c;
    while (c = *str++)
        val = val << 5 + val + c;
    
    return val % TABLE_SIZE;
}

char _strcpy(char dst[], char src[])
{
    for (int i = 0; i < LEN && src[i]; ++i)
        dst[i] = src[i];
}

void init()
{
    dbCount = 0;
    for (int i = 0; i < FIELD_SIZE; ++i)
    {
        for (int j = 0; j < TABLE_SIZE; ++j)
        {
            hash_table[i][j][0] = 0;
        }
    }
}

void insert(char name[], char email[])
{
    db[dbCount].active = true;
    _strcpy(db[dbCount].str[NAME], name);
    _strcpy(db[dbCount].str[EMAIL], email);
    
    //name hash table
    int n;
    unsigned long key = hash_func(name);
    n = hash_table[NAME][key][0];
    hash_table[NAME][key][n + 1] = dbCount;
    hash_table[NAME][key][0]++;

    key = hash_func(email);
    n = hash_table[EMAIL][key][0];
    hash_table[EMAIL][key][n + 1] = dbCount;
    hash_table[EMAIL][key][0]++;

    dbCount++;
}   


result search(field f, char str[], field outf)
{
    result output;
    unsigned long key = hash_func(str);
    int n;
    int index;
   
    n = hash_table[f][key][0];
    int j = 0;
    for (int i = 1; i <= n; ++i)
    {
        index = hash_table[f][key][i];
        if (db[index].active && !strcmp(db[index].str[f], str))
        {
            output.count++;
            _strcpy(output.str[j++], db[index].str[outf]);
            
        }
    }

    return output;
}

void del(field f, char str[])
{
    unsigned long key = hash_func(str);
    int index(0);
    int n = hash_table[f][key][0];
    for (int i = 1; i <= n; ++i)
    {
        index = hash_table[f][key][i];
        if (db[index].active && !strcmp(db[index].str[f], str))
            db[index].active = false;
    }
}

void change(field inf, char str[], field cf, char cstr[])
{
    unsigned long key = hash_func(str), key2;
    int index;
    int n = hash_table[inf][key][0];
    for (int i = 1; i <= n; ++i)
    {
        index = hash_table[inf][key][i];
        if (db[index].active && !strcmp(db[index].str[inf], str))
        {
            _strcpy(db[index].str[cf], cstr);
            key2 = hash_func(cstr);
            hash_table[cf][key2][hash_table[cf][key2][0] + 1] = index;
            hash_table[cf][key2][0]++;
        }
    }
}

int main()
{
    insert("ami", "ami@ami.com");
    insert("ami", "ami1@ami.com");

    insert("Amitesh", "amitesh@gmail.com");

    cout << "searching for ami: ";
    {
        result o = search(NAME, "ami", EMAIL);
        cout << o.count << " : ";
        for (int i = 0; i < o.count; ++i)
            cout << o.str[i] << "\n";
    }
    //deleting ami1@ami.com
    del(EMAIL, "ami1@ami.com");

    {
        result o = search(EMAIL, "ami1@ami.com", NAME);
        cout << o.count << ": ";
        cout << (o.count ? "found" : "not found");
        for (int i = 0; i < o.count; ++i)
            cout << o.str[i] << "\n";
    }

    change(NAME, "ami", NAME, "Amitesh");
    cout << "Searching for Amitesh: ";
     {
        result o = search(NAME, "Amitesh", EMAIL);
        cout << o.count << " : ";
        for (int i = 0; i < o.count; ++i)
            cout << o.str[i] << "\n";
    }
    return 0;
}