#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
   int temp;

   temp = *a;
   *a = *b;
   *b = temp;
}

int partition(int A[], int low, int high)
{
   int pivot, index, i;

   index = low;
   pivot = high;

   for (i = low; i < high; ++i)
     {
        if (A[i] < A[pivot])
          {
             swap(&A[i], &A[index]);
             index++;
          }
     }

   swap(&A[pivot], &A[index]);

   return index;
}

int randomPartition(int A[], int low, int high)
{
   int pivot;

   pivot = low + rand() % (high - low + 1);

   swap(&A[high], &A[pivot]);

   return partition(A, low, high);
}

void quickSort(int A[], int low, int high)
{
   int pivot;

   if (low < high)
     {
        //pivot = partition(A, low, high);
        // 3 steps
        // 1. find the random pivot
        // 2. 3 partitions
        //    left part less than pivot (excluding pivot)
        //    right part greater or equal to pivot 
        //    and pivot itself
        // 3. apply merge sort to left part, then right and then pivot
        pivot = randomPartition(A, low, high);
        quickSort(A, low, pivot - 1);
        quickSort(A, pivot + 1, high);
     }
}

void print(int A[], int n)
{
   for (register int i = 0; i < n; ++i)
     {
        cout << A[i] << " ";
     }
   cout << endl;
}

int main()
{
   int A[] = {1, 4, 9, 3, -1, 98, 1234, 45, 234, 2134, 2442};

   quickSort(A, 0, sizeof(A)/sizeof(int) - 1);

   print(A, sizeof(A)/sizeof(int));
   return 0;
}
