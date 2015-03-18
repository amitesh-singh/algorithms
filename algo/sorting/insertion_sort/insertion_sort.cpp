#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;
template<class T>
void myswap(T &a,T &b)
{
    T temp;
    temp = a;
    a=b;
    b = temp;
}
void insertion_sort(int A[],int n)
{
    for(int i = 1;i<n;++i)
    {
        int temp = A[i];
        int j = i-1;
        for(;temp < A[j] && j>=0;--j)
        {
            A[j+1] = A[j];
        }
        A[j+1] = temp;
    }
}


int main()
{
    int arr[] = {10,11,20,1,2,4,0,10};
    insertion_sort(arr,8);
    std::copy(arr,arr+8,std::ostream_iterator<int>(cout," "));
    cout << std::endl;

    return 0;
}
