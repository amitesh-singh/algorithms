#include <iostream>

using namespace std;

int partition(int [], int, int);

int randomizedPartition(int a[], int p, int r)
{
    int index = p + rand() % (r - p + 1);
    std::swap(a[index], a[r]);

    return partition(a, p, r); 
}

// use left and right index, pivot is a[end]
// keep checking until condition is not met. 
// check at both side, from left and right
//
int partition(int a[], int p, int r)
{
    int left = p;
    int right = r - 1;
    int pivot = a[r];

    bool done = false;

    while (!done)
    {
        while (left < r && pivot > a[left])
            left++;
        while (right > p && pivot < a[right])
            right--;
        
        if (left >= right)
            done = true;
        else
        {
            std::swap(a[left], a[right]);
        }
    }

    std::swap(a[r], a[left]);
    return left;
}

void quicksort(int a[], int p, int r, bool randomized = false)
{
    if (p >= r) return;

    int q;
    if (!randomized)
        q = partition(a, p, r);
    else
        q = randomizedPartition(a, p, r);

    quicksort(a, p, q - 1);
    quicksort(a, q + 1, r);
}

int main()
{
    srand(time(nullptr));

    int a[] {100, 0, -1, 23, 45, 445, 90};
    int b[] {0, 1, 2, -1, 3, 6, -3, -1, -10};
    int aSize = sizeof(a)/sizeof(int);
    int bSize = sizeof(b)/sizeof(int);

    quicksort(a, 0, aSize - 1);
    quicksort(b, 0, bSize - 1, true);

    for (int i = 0; i < aSize; ++i)
        cout << a[i] << ", ";
    
    cout << endl;

    for (int i = 0; i < bSize; ++i)
        cout << b[i] << ", ";

    cout << endl;
    
    return 0;
}