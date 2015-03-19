#include<iostream>
using namespace std;
int main()
{
    int x = 1;
    const int *pX  = &x; //pointer to const int
    //*pX = 10; compilation error
    cout << *pX << " ," << x << endl;
    const int x2 = 2;
    int *pX2 = const_cast<int *>(&x2);
    cout << *pX2 << " ," << x2 << endl;
    *pX2 = 11;
    cout << *pX2 << " ," << x2 << endl; //undefined behavior

    
    return 0;
}
