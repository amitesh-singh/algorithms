#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

template<class T>
void Merge(T A[], int low, int mid,int high);

template<class T>
void MergeSort(T A[],int low,int high)
{
   if (low >= high) return;
   int mid = (high + low)/2;
   MergeSort(A, low, mid);
   MergeSort(A, mid + 1, high);
   Merge(A, low, mid, high);
}

template<class T>
void Merge(T A[],int low, int mid, int high)
{
   int left = low, right = mid + 1;
   int index = 0;
   int *temp = new int[high - low + 1];

   while (left <= mid && right <= high)
     {
        if (A[left] <= A[right])
          {
             temp[index++] = A[left++];
          }
        else
          {
             temp[index++] = A[right++];
          }
     }

   if (left > mid)
     {
        for (int i = right; i <= high; ++i)
          temp[index++] = A[i];
     }
   else
     {
        for (int i = left; i <= mid; ++i)
          temp[index++] = A[i];
     }

   for (int i = 0; i < high - low + 1; ++i)
     {
        A[i + low] = temp[i];
     }

   delete [] temp;
}

int main()
{
   int A[] = {10,1,3,4,74,2};
   int n = sizeof(A)/sizeof(int);
   for (int i = 0; i < n; ++i)
     cout << A[i] << ", ";
   cout << endl;

   MergeSort(A,0, n - 1);
   
   for (int i = 0; i < n; ++i)
     cout << A[i] << ", ";

   cout << endl;

   return 0;
}
