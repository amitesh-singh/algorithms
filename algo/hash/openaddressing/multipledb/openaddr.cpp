// implement a db like
// ["name"] = "email";
// ["email"] = "name"

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_LEN 30

//we are  going to implement following APIs
// 1 < N < 100000
void insert(char name[MAX_LEN], char email[MAX_LEN]);
void del(char name[MAX_LEN]);
void get(char name_in[MAX_LEN], char email_out[MAX_LEN]);
void getName(char email_in[MAX_LEN], char name_out[MAX_LEN]);

#define FILL 1
#define EMPTY 0

struct hashtable
{
   char name[MAX_LEN];
   char email[MAX_LEN];
   int status;
};

static const int hashtablesize = 10001;
static hashtable namehash[hashtablesize*100];
static hashtable emailhash[hashtablesize*100];

inline unsigned long hashfunc(char *str)
{
   unsigned long val = 5381;
   int c;

   while (c = *str++)
     val = (val << 5) + val + c;

   return val;
}

inline unsigned long hashmod(unsigned long key)
{
   return key % hashtablesize;
}

void hashinsert(int &hashindex, hashtable *ht, char name[MAX_LEN], char email[MAX_LEN])
{
   int index = hashindex;

   while (ht[index].status == 1)
     {
        index = (index + 1) % hashtablesize;
        if (index == hashindex)
          {
             cerr << __func__ << "hash is full\n";
             abort();
          }
     }

   ht[index].status = 1;
   strcpy(ht[index].name, name);
   strcpy(ht[index].email, email);

}

void search(char data[MAX_LEN], hashtable *ht, char dataout[MAX_LEN], int datatype)
{
   int hashindex = hashmod(hashfunc(data));
   int index = hashindex;

   while (ht[index].status == FILL)
     {
        if (datatype == 1)
          {
             if (!strcmp(data, ht[index].name))
               {
                  strcpy(dataout, ht[index].email);
                  cout << ht[index].email << endl;
                  cout << "found\n";
                  return;
               }
          }
        else
          {
             if (!strcmp(data, ht[index].email))
               {
                  strcpy(dataout, ht[index].name);
                  cout << "found\n";
                  return;
               }
          }
        index = (index + 1) % hashtablesize;
        if (index == hashindex)
          {
             cerr << "not found\n";
             return;
          }
     }
}

void del(char data[MAX_LEN], hashtable *ht)
{
   int hashindex = hashmod(hashfunc(data));
   int index = hashindex;

}

void insert(char name[MAX_LEN], char email[MAX_LEN])
{
   int nameindex = hashmod(hashfunc(name));
   int emailindex = hashmod(hashfunc(email));

   cout << "name index: " << nameindex << endl;
   cout << "email index: " << emailindex << endl;

   hashinsert(nameindex, namehash, name, email);
   hashinsert(emailindex, emailhash, name, email);
}
void get(char name_in[MAX_LEN], char email_out[MAX_LEN])
{
   search(name_in, namehash, email_out, 1);
}

void getName(char email_in[MAX_LEN], char name_out[MAX_LEN])
{
   search(email_in, emailhash, name_out, 0);
}

void del(char name[MAX_LEN])
{
   int hashindex = hashmod(hashfunc(name));

   int index = hashindex;

   while (namehash[index].status == FILL)
     {
        if (!strcmp(name, namehash[index].name))
          {
             break;
          }
        index = (index + 1) % hashtablesize;
        if (index == hashindex)
          {
             cerr << "del - unable to delete, data available\n";
             return;
          }
     }

   namehash[index].status = EMPTY;

   int emailindex = hashmod(hashfunc(namehash[index].email));
   int i = emailindex;

   while (emailhash[i].status == FILL)
     {
        if (!strcmp(namehash[index].email, emailhash[i].email))
          {
             break;
          }
        i = (i + i) % hashtablesize;
        if (i == emailindex)
          {
             cerr << "not found\n";
             return;
          }
     }

   emailhash[index].status = EMPTY;
}

int main()
{
   insert("Google", "someone@google.com");
   insert("MS", "someone@ms.com");
   insert("sami", "someone@sami.com");

   char name[MAX_LEN], email[MAX_LEN];

   get("Google", email);

   cout << email << endl;

   return 0;
}


