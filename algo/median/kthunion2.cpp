#include<iostream>
using namespace std;

int getNth(int * v, int nv, int * w, int nw, int nth) {
    int leftv, rightv, midv,   leftw, rightw, midw;
    leftv = leftw = 0;
    rightv = nv-1;
    rightw = nw-1;
    while (leftv <= rightv && leftw <= rightw)
    {
        midv = (leftv + rightv) / 2;
        midw = (leftw + rightw) / 2; 
 
        int a = midv - leftv+1, b = midw - leftw+1;
        if (a+b > nth)
        {
            if (v[midv] > w[midw]) 
                rightv = midv - 1;
            else 
                rightw = midw - 1;
        }
        else if (v[midv] < w[midw])
        {
            leftv = midv+1;
            nth -= a;
        }
        else 
        {
            leftw = midw+1;
            nth -= b;
        }
    }
    if (leftv <= rightv) 
        return v[leftv + nth - 1]; // check where is the answer
    else
        return w[leftw + nth - 1];
}


int main()
{
    int A[] = {1,2,3};
    int B[] = {4,5,6};
    cout << getNth(A,3,B,3,3);
    return 0;
}
