#include <iostream>

using namespace std;

int stack[1001];


int partition(int a[], int low, int high)
{
   int i, index, pivot;

   pivot = high;
   index = low;

   for (i = low; i < high; ++i)
     {
        if (a[i] < a[pivot])
          {
             swap(a[i], a[index]);
             index++;
          }
     }

   swap(a[index], a[pivot]);

   return index;
}

void qSort(int a[], int low, int high)
{
   int top = -1;

   stack[++top] = low;
   stack[++top] = high;

   while (top >= 0)
     {
        //pop out h and low
        high = stack[top--];
        low = stack[top--];

        int pivot = partition(a, low, high);

        if (pivot - 1 > low)
          {
             stack[++top] = low;
             stack[++top] = pivot - 1;
          }

        if (pivot + 1 < high)
          {
             stack[++top] = pivot + 1;
             stack[++top] = high;
          }
     }

}

int main()
{
   int a[] = {1, 34, 3452, 22, 32, -1, 34, 234};

   qSort(a, 0, sizeof(a)/sizeof(int)  -1);
   for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
     cout << a[i] << " ";

   cout << endl;
   return 0;
}
