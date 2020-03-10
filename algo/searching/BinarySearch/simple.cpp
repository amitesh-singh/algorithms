#include <iostream>

using namespace std;

int binarySearchRecursive(int a[], int low, int high, int k)
{
   int mid;
   if (low <= high)
   {
        mid = (low + high) / 2;
        if (a[mid] == k)
            return mid;
        if (k > a[mid])
            return binarySearchRecursive(a, mid + 1, high, k);
        else
            return binarySearchRecursive(a, low, mid - 1, k);
   }

   return -1;
}

int binarySearch(int a[], int low, int high, int key)
{
    int mid;

    while (low <= high)
    {
        mid = low + (high - low)/2;
        if (key < a[mid])
            high = mid - 1;
        else if (key > a[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

//used for finding range
int lowerbound(int a[], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low)/2;
        if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int higherbound(int a[], int low, int high, int key)
{
    int mid;

    while (low <= high)
    {
        mid = low + (high - low)/2;
        if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return high;
}

void findRange(int a[], int low, int high, int leftVal, int rightVal)
{
    int left = lowerbound(a, low, high, leftVal);
    int right = higherbound(a, left, high, rightVal);

    cout << "(" << left << "," << right << ")" << endl;
}

int main()
{
    int a[] = {1, 3, 4, 5, 9, 10, 11, 43, 45, 56, 89, 90, 91, 97};
    int n = sizeof(a)/sizeof(int);

    cout << "find 11: " << binarySearch(a, 0, n - 1, 11) << endl;
    cout << "find 97 :" << binarySearch(a, 0, n -1, 97) << endl;
    cout << "find 56 using binarySearchRecursive: " << binarySearchRecursive(a, 0, n - 1, 56) << endl;

    cout << "lowerbound(45): " << a[lowerbound(a, 0, n - 1, 45)] << endl;
    cout << "higher bound(92) " << a[higherbound(a, 0, n - 1, 92)] << endl;

    findRange(a, 0, n - 1, 45, 92);

    return 0;   
}
