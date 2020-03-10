#include <iostream>
#include <algorithm>

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
    int l = low;
    int h = high + 1;

    while (l < h)
    {
        mid = (l + h)/2;
        if (key <= a[mid])
            h = mid;
        else
            l = mid + 1;
    }

    return l;
}

int upperbound(int a[], int low, int high, int key)
{
    int mid;
    int l = low;
    int h = high + 1;

    while (l < h)
    {
        mid = (l + h) / 2;
        if (key >= a[mid])
            l = mid + 1;
        else
            h = mid;
    }

    return l;
}

void findRange(int a[], int low, int high, int leftVal, int rightVal)
{
    int left = lowerbound(a, low, high, leftVal);
    int right = upperbound(a, left, high, rightVal);

    cout << "(" << left << "," << right << ")" << endl;
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << ", ";
    cout << "\n";
}
#include <vector>

int main()
{
    int a[] = {1, 3, 4, 5, 9, 10, 11, 43, 45, 56, 89, 90, 91, 97};
    int n = sizeof(a)/sizeof(int);

    printArr(a, n);

    cout << "find 11: " << binarySearch(a, 0, n - 1, 11) << endl;
    cout << "find 97 :" << binarySearch(a, 0, n -1, 97) << endl;
    cout << "find 56 using binarySearchRecursive: " << binarySearchRecursive(a, 0, n - 1, 56) << endl;

    cout << "lower,upper bound of 46: " << lowerbound(a, 0, n - 1, 46) << ", " 
         << upperbound(a, 0, n - 1, 46)<< endl;
    //using std::lower_bound, upper_bound
    cout << "index: " << (std::lower_bound(a, a + (n - 1), 46) - a) << " " << *(std::lower_bound(a, a + (n - 1), 46)) << endl;

    findRange(a, 0, n - 1, 45, 92);

    vector<int> v {100, 23, 123, -9, 0, 23, 342, 98, 45};

    std::sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ", ";
    cout << "\n";
    
    if (std::binary_search(v.begin(), v.end(), 23))
        cout << "23 is found\n";
    cout << "lower,upper_bound for 23: (" << std::lower_bound(v.begin(), v.end(), 23) - v.begin() << ", "
         << std::upper_bound(v.begin(), v.end(), 23) - v.begin() << ")" << std::endl;

    return 0;   
}
