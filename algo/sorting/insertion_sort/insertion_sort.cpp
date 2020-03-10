#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

void insertion_sort(int a[],int n)
{
    for(int i = 1; i < n; ++i)
    {
        int temp = a[i];
        int j = i-1;

        for(;temp < a[j] && j>=0;--j)
        {
            a[j+1] = a[j];
        }

        a[j+1] = temp;
    }
}


int main()
{
    int arr[] = {10,11,20,1,2,4,0,10};
    int arrSize = sizeof(arr)/sizeof(*arr);

    insertion_sort(arr, arrSize);

    std::copy(arr,arr+8,std::ostream_iterator<int>(cout," "));
    cout << std::endl;

    return 0;
}
