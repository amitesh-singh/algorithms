//But this does not improve any performace until the array is huge
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

void merge(int a[], int low, int mid, int high)
{
    int left {low}, right {mid + 1};
    int index {0};
    int *temp = new int[high - low + 1];

    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
            temp[index++] = a[left++];
        else
            temp[index++] = a[right++];
    }

    if (left > mid)
    {
        for (int i = right; i <= high; ++i)
            temp[index++] = a[i]; 
    }
    else
    {
        for (int i = left; i <= mid; ++i)
            temp[index++] = a[i];
    }

    for (int i = 0; i <= high - low; ++i)
        a[i + low] = temp[i];

    delete [] temp;
}

void mergeSort(int a[], int low, int high)
{
    if (low >= high) return;
    int mid = low + (high - low)/2;

    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    int a[] {1, 2, 6, 3, -1, 890, 234, 345, 123, 43, 222, 44};
    int b[] {1, 2, 6, 3, -1, 890, 234, 345, 123, 43, 222, 44};

    int aSize = sizeof(a)/sizeof(int);
    
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        
        mergeSort(b, 0, aSize - 1);
        
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "Took: " 
            << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()
             << " microseconds." << std::endl;
        printArr(b, aSize);
    }
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        
        std::thread th1(mergeSort, a, 0, aSize/2);
        std::thread th2(mergeSort, a, aSize/2 + 1, aSize - 1);
        th1.join();
        th2.join();
        merge(a, 0, aSize/2, aSize - 1);

        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "using thread, Took: " 
            << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() 
            << " microseconds." << std::endl;
        printArr(a, aSize);
    }

    return 0;
}