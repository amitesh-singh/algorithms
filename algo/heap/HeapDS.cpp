#include <iostream>

using  namespace std;

enum HeapType
{
   MAX,
   MIN
};

#define MAX_CAPACITY 1001
template<HeapType ht>
class heap
{
 public:
    int A[MAX_CAPACITY];
    int length; // it start with index 0
    int heapsize; //it starts with index 1

    heap(int arr[], int len): length(len)
   {
      for (int i = 1; i <= len; ++i)
        {
           A[i] = arr[i - 1];
        }
   }

    int parent(int i)
      {
         return i/2;
      }

    int left(int i)
      {
         return 2*i;
      }

    int right(int i)
      {
         return 2*i + 1;
      }

    void build()
      {
         heapsize = length;

         for (int i = heapsize/2; i >= 1; --i)
           {
              heapify(i);
           }
      }

    void heapify(int i)
      {
         int l = left(i);
         int r = right(i);
         int largest = 0, smallest = 0;

         if (ht == MAX)
           {
              if (l <= heapsize && A[i] < A[l])
                largest = l;
              else
                largest = i;

              if (r <= heapsize && A[largest] < A[r])
                largest = r;

              if (largest != i)
                {
                   std::swap(A[i], A[largest]);
                   heapify(largest);
                }
           }
         else
           {
              if (l <= heapsize && A[i] > A[l])
                smallest = l;
              else
                smallest = i;
              if (r <= heapsize && A[smallest] > A[r])
                smallest = r;
              if (smallest != i)
                {
                   std::swap(A[i], A[smallest]);
                   heapify(smallest);
                }
           }
      }

    void print()
      {
         for (int i = 1; i <= heapsize; ++i)
           {
              cout << A[i] << " ";
           }

         cout << endl;
      }

    int getMin()
      {
         return A[1];
      }

    int getMax()
      {
         return getMin();
      }

    int pop()
      {
         int ret = A[1];

         A[1] = A[heapsize];
         heapsize--;

         heapify(1);

         return ret;
      }

    void insert(int key)
      {
         if ((heapsize + 1) >= MAX_CAPACITY)
           {
              cout << "heap is full, delete  some\n";
              return;
           }
         //insert the key to end of heapsize
         A[++heapsize] = key;
         int i = heapsize;
         if (ht == MAX)
           {
              while (i != 1 && A[parent(i)] < A[i])
                {
                   std::swap(A[parent(i)], A[i]);
                   i = parent(i);
                }
           }
         else
           {
              while (i != 1 && A[parent(i)] > A[i])
                {
                   std::swap(A[parent(i)], A[i]);
                   i = parent(i);
                }
           }
      }
};

int main()
{
   int arr[] = { 4, 5 , 9, -1, 0, 98, 234, 45};
   
   cout << "\nMax heap: \n";
   cout << endl;
   heap<MAX> maxheap(arr, sizeof(arr)/sizeof(int));
   maxheap.build();
   maxheap.print();

   cout << "max is " << maxheap.getMax() << endl;
   maxheap.pop();

   cout << "max is " << maxheap.getMax() << endl;
   maxheap.print();

   cout << "inserting 11 into heap:\n";
   maxheap.insert(11);
   maxheap.print();
   cout << "max now is: " << maxheap.pop() << endl;

   cout << "\nMin heap: \n\n";

   heap<MIN> minheap(arr, sizeof(arr)/sizeof(int));
   minheap.build();
   minheap.print();

   cout << "min is: " << minheap.getMin() << endl;
   minheap.pop();
   minheap.print();

   minheap.insert(11);
   minheap.print();
   cout << "min now is and popped it: " << minheap.pop() << endl;

   return 0;
}
