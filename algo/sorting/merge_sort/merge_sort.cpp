#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

template<class T>
void Merge(T A[],int,int ,int );
template<class T>
void MergeSort(T A[],int p,int r)
{
    int q = 0;
    if(p<r)
    {
        q = (p+r)/2;

        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q+1,r);
    }
}
template<class T>
void Merge(T A[],int p,int q ,int r)
{
    cout << "p:" << p << " q:" << q << " r:" << r << endl;
    int n1 = q-p;
    int n2 = r-q;
    T *L = new T[n1];
    T *R = new T[n2];

    for(int i =0;i<n1;++i)
        L[i] = A[p-i];
    for(int j =0;j<n2;++j)
        R[j] = A[q+j];

    copy(L,L+n1,ostream_iterator<int>(cout," "));
    cout << "\n";
    copy(R,R+n2,ostream_iterator<int>(cout," "));
    cout << "\n";

    int i = 0,j = 0,k=0;
    while(i <=(q-1) && j<=(r-1))
    {
        if(L[i] <= L[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    delete [] L;
    delete [] R;
    
}
int main()
{
    int A[] = {10,1,3,4,74,2};
    MergeSort(A,0,6);
    std::copy(A,A+6,ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
