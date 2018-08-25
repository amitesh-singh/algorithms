#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;


template<class T>
class Heap
{
   T *mArr;
   int mSize;

 protected:
   int getParent(int i){return i>>1;}
   int getLeft(int i){return i<<1;}
   int getRight(int i){return (i<<1 + 1);}
 public:
   void maxHeapify(T  A[],int i)
     {
        //i = i+1;
        int l = getLeft(i),r = getRight(i);
        int largest(0);
        if(A[i] < A[l] && l<=mSize)
          largest = l;
        else
          largest = i;

        if(A[largest] < A[r] && r <=mSize)
          largest = r;

        if(largest != i)
          {
             std::swap(A[i],A[largest]);
             maxHeapify(A,largest);
          }
     }

   void heapSort()
     {
        int n = mSize;
        int *temp = new int[mSize];
        int k = 0;
        for(int i =n;i>0;--i)
          {
             temp[k++] = mArr[0];
             //cout << mArr[0] << ",";
             mArr[0] = mArr[i];
             mSize--;
             maxHeapify(mArr,1);
          }

        std::copy(temp,temp+mSize,std::ostream_iterator<int>(cout,","));
        cout << "\n";

        delete [] temp;
     }

   void heapify()
     {
        for(int i =(mSize/2);i>=0;i--)
          maxHeapify(mArr,i);
     }

 public:
   Heap(T arr[],int size):mArr(arr),mSize(size)
   {
   }

   void print()
     {
        std::copy(mArr,mArr+mSize,std::ostream_iterator<T>(cout,","));
        cout << endl;
     }

};


int main()
{
   int A[] = {1,2,4,0,-1,9,10};
   Heap<int> heap(A,7);
   heap.print();
   heap.heapify();
   heap.print();
   std::copy(A,A+7,std::ostream_iterator<int>(cout,"; "));
   cout << endl;

   heap.heapSort();

   return 0;
}
