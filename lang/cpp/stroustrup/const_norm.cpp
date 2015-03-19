#include<iostream>
using namespace std;

int main()
{
    const int i = 5;
    int *p = (int *)&i;
    *p = 11;
    cout << i << endl; //result in undefined.
    return 0;
}
