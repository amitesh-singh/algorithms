#include <iostream>
#include <algorithm>

//interpolation search, improvement over binary search
//instead of starting from mid, we start from pos which is calculated using below formula:
//
// pos = start + ((double)(end - start)/(a[end]- a[start]))*(key - a[start]);
//If elements are uniformly distributed, then O (log log n)).
// In worst case it can take upto O(n).


int interpolationSearch(int a[], int low, int high, int key)
{
    int pos;
    
    while (low <= high && key >= a[low] && key <= a[high])
    {
        pos = low + ((double)(high - low)/(a[high] - a[low])) * (key - a[low]);
        if (a[pos] == key) return pos;
        else if (key > a[pos])
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int main()
{
    int a[] {10, 23, 234, 2332, 42, -1, 90};
    int aSize = sizeof(a)/sizeof(int);
    
    std::sort(a, a + aSize);
    
    for (int i = 0;i < aSize; ++i)
        std::cout << a[i] << ", ";
    std::cout << std::endl;

    int pos = interpolationSearch(a, 0, aSize - 1, 234);
    std::cout << "position of 234 is: " << pos << std::endl;
    std::cout << "position of -1: " << interpolationSearch(a, 0, aSize - 1, -1) << std::endl;
    return 0;
}

