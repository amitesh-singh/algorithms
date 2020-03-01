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

int main(int argc, char **argv)
{
   if (argc != 4)
     {
        std::cerr << argv[0] << "<array size> <option, 2 or 4 threads> <verbose enabled/false, 1 or 0>\n";
        exit(1);
     }
   int option = atoi(argv[2]);
   if (option != 2 &&  option != 4)
   {
       std::cerr << "Enter 2 or 4 only.\n";
       exit(2);
   }

   int aSize = atoi(argv[1]);
   int verbose = atoi(argv[3]);

   srand(time(NULL));
   int *a = new int[aSize];
   int *b = new int[aSize];
   
   for (int i = 0; i < aSize; i++)
   {
       a[i] = rand();
       b[i] = rand();
   }
   
    {
        auto t1 = std::chrono::high_resolution_clock::now();

        mergeSort(b, 0, aSize - 1);

        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "Took: " 
           << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()
           << " microseconds." << std::endl;
        if (verbose)
            printArr(b, aSize);
    }

    {
        if (option == 2)
          {
             auto t1 = std::chrono::high_resolution_clock::now();

             std::thread th1(mergeSort, a, 0, aSize/2);
             std::thread th2(mergeSort, a, aSize/2 + 1, aSize - 1);
             th1.join();
             th2.join();
             merge(a, 0, aSize/2, aSize - 1);

             auto t2 = std::chrono::high_resolution_clock::now();

             std::cout << "using " << option << " thread, Took: " 
                << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() 
                << " microseconds." << std::endl;
          }
        else if (option == 4)
          {
             auto t1 = std::chrono::high_resolution_clock::now();

             //using 4 threads
             std::thread th1(mergeSort, a, 0, aSize/4);
             std::thread th2(mergeSort, a, aSize/4 + 1, aSize/2);
             std::thread th3(mergeSort, a, aSize/2 + 1, 3*aSize/4);
             std::thread th4(mergeSort, a, 3*aSize/4 + 1, aSize - 1);
             th1.join();
             th2.join();
             th3.join();
             th4.join();

             merge(a, 0, aSize/4, aSize/2);
             merge(a, aSize/2 + 1, 3*aSize/4, aSize - 1);
             merge(a, 0, aSize/2, aSize - 1);

             auto t2 = std::chrono::high_resolution_clock::now();
             std::cout << "using " << option << " thread, Took: " 
                << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() 
                << " microseconds." << std::endl;
          }
        if (verbose)
            printArr(a, aSize);
    }
    delete [] a;
    delete [] b;
   return 0;
}
