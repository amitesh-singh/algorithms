#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;


void selection_sort(int A[],int n)
{
    for(int i = 0;i<n-1;++i)
    {
        int pos = i;
        for(int j = i+1;j<n;++j)
        {
            if(A[j] < A[pos])
                pos = j;
        }
        std::swap(A[pos],A[i]);
    }
}
int main()
{
    int arr[] = {1,4,3,10,9,6,5};
    selection_sort(arr,7);
    copy(arr,arr+7,ostream_iterator<int>(cout, " "));
    cout << "\n";


    return 0;
}
