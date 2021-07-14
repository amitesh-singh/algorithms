#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

void insertion_sort(int a[],int n)
{
    int j;

    for (int i = 1; i < n; ++i)
    {
        j = i;
        while (j > 0 and a[j] < a[j-1])
        {
            std::swap(a[j], a[j-1]);
            j--;
        }
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
