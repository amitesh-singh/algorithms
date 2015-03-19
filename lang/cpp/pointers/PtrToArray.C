#include<iostream>
using namespace std;

int main()
{
    int *arr1[8];
    int (*arr2)[8];

    //on 64 bits,sizeof(arr2) = 8 bytes
    //on 32 bits, sizeof(arr2) = 4 bytes
    cout << sizeof(arr2) << endl;

    return 0;
}
