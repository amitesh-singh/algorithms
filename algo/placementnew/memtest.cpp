#include <iostream>

using namespace std;

char mempool[101];
int memIndex = 0;

//overload delete

void operator delete(void *ptr)
{
   //don't do anything
}

int main()
{
    int *p1 = new (mempool + memIndex) int;
    memIndex += sizeof(int);
    *p1 = 1;

    int *p2 = new (mempool + memIndex) int;
    memIndex += sizeof(int);
    *p2 = 2;

    char *c = new (mempool + memIndex) char;
    memIndex += sizeof(char);
    *c = 'A';

    cout << "mem index: " << memIndex << endl;
    delete c;

    //print the mempool
    cout << std::hex;
    for (int i = 0; i < memIndex; ++i)
    {
        cout << std::hex << int(mempool[i]) << " ";
    }
    cout << "\n";

    return 0;
}
