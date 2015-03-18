#include<iostream>
using namespace std;


template<class T>
T findKth(T A[],int nv,T B[],int nw,int nth)
{
    int leftv =0,rightv = nv-1;
    int leftw = 0,rightw = nw-1;
    int midv,midw;
    while(leftv <= rightv && leftw <= rightw)
    {
        midv = (leftv + rightv)/2;
        midw = (leftw + rightw)/2;
        int a = midv - leftv + 1;
        int b = midw - leftw + 1;

        if((a+b) > nth)
        {
            if(A[midv] > B[midw])
                rightv = midv-1;
            else
                rightw = midw -1;
        }
        else if(A[midv] < B[midw])
        {
            leftv = midv + 1;
            nth-=a;
        }
        else
        {
            leftw = midw + 1;
            nth-=b;
        }
    } // while ends
    if(leftv <= rightv)
        return A[leftv + nth -1];
    else
        return B[leftw + nth -1];
}

int main()
{
    int A[] = {1,2,3};
    int B[] = {4,5,6};

    cout << findKth(A,3,B,3,2);

    return 0;
}

