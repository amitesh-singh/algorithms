#include<iostream>
using namespace std;

template<class T>
int findInvAcross(T A[],int p,int q,int r)
{
    int i = p,j=q,k=r;
    int invCount = 0;

    while(i<=(q-1) && j<=r)
    {
        if(A[i] < A[j])
        {
            i++;
        }
        else
        {
            invCount+=q-i;
            j++;
            break;
        }
        k++;
    }

    return invCount;
}

template<class T>
int findInvCount(T A[],int p,int r)
{
    int invCount(0); 
    int q = 0;
    if(p < r)
    {
        q = (p+r)/2;
        invCount += findInvCount(A,p,q);
        invCount += findInvCount(A,q+1,r);
        invCount += findInvAcross(A,p,q+1,r);
    }
    return invCount;
}
int main()
{
    int A[] = {1,2,4,0,9,10};
    cout << findInvCount(A,0,6);
    return 0;
}
