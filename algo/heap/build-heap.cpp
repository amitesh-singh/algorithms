#include <iostream>
#include <cstdio>

int left(int i)
{
   return i << 1;
}

int right(int i)
{
   return (i << 1) + 1;
}

int parent(int i)
{
   return i >> 1;
}

using namespace std;

void minHeapify(int a[], int n, int i)
{
   int l, r;

   l = left(i);
   r = right(i);
//   cout << "l: " << l << " r: " << r << endl;
   int smallest;

   if (l <= n && a[l] < a[i])
     smallest = l;
   else
    smallest = i;

   if (r <= n && a[r] < a[smallest])
     smallest = r;

   if (smallest != i)
     {
        swap(a[i], a[smallest]);
        //cout << "Swap: " << a[i] << "<-->" << a[smallest] << endl;
        minHeapify(a, n, smallest);
     }
}

void buildHeap(int a[], int n)
{
   for (int i = n/2 ; i >= 1; --i)
     {
        minHeapify(a, n, i);
     }
}

void printArr(int a[], int n)
{
   for (int i = 1; i <= n; ++i)
     cout << a[i] << " ";

   cout << endl;
}

int A[100];

int main()
{
   freopen("input.txt", "r", stdin);

   int T, N;
   cin >> T;

   for (int testCase = 1; testCase <= T; ++testCase)
     {
        cin >> N;
        for (int i = 1; i <= N; ++i)
          {
             cin >> A[i];
          }

        buildHeap(A, N);
        printArr(A, N);

        printf("Min: %d\n", A[1]);
     }

   return 0;
}
