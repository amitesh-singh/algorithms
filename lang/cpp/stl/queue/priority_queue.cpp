#include <queue>
#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#define F std::cout << __PRETTY_FUNCTION__ << std::endl

void f1()
{
   std::priority_queue<int> pq;
   
   F;
   for (int i = 0; i < 10; ++i)
      pq.push(i);

   for (int i = 0; i < 10; ++i)
   {
         std::cout << pq.top() << ", ";
         pq.pop();
   }
   std::cout << std::endl;
}

void f2()
{
   F;
   std::cout << "min heap: ";
   std::priority_queue<int, std::vector<int>, std::greater<int> > pq; //min heap
   for (int i = 0; i < 10; ++i)
      pq.push(i);

   for (int i = 0; i < 10; ++i)
      {
         std::cout << pq.top() << ", ";
         pq.pop();
      }
      std::cout << std::endl;
}

//pq for fixed size lets say 5

namespace nonstd
{
   template<class T>
   class fixed_size_pqueue
   {
      std::list<T> _data;
      int _fixed_size;
      public:
      fixed_size_pqueue(int fixed_size)
      {
         _fixed_size = fixed_size;
      }

      void push(T &d)
      {
         if (_data.size() == _fixed_size)
         {
            T min = _data.back();
            if (d > min)
               _data.pop_back();
         }
         _data.push_back(d);
         _data.sort(std::greater<T>{});
      }

      T pop()
      {
         T d = _data.back();
         _data.pop_back();
         //_data.sort();
         return d;
      }

      T top() const
      {
         return _data.back();
      }

      int size() const
      {
         return _data.size();
      }
   };

   template<class T, int fixed_size = 5>
   class fixed_size_arr_pqueue_v1
   {
      std::array<T, fixed_size> _data;
      int _size = 0;

      public:
      /*
      void print()
      {
         for (auto &x: _data)
            std::cout << x << " , ";
         std::cout << std::endl;
      }
      */

      void push(T &d)
      {
         if (_size == fixed_size)
         {
            //min elements in a max heap lies at leaves only. 
            auto minItr = std::min_element(begin(_data) + _size/2, end(_data));
            auto minPos {minItr - _data.begin()};
            auto min { *minItr};
            
            if (d > min)
            {
               _data.at(minPos) = d;
               std::make_heap(begin(_data), end(_data));
            }           

            return ;
         }

         _data.at(_size++) = d;
         std::push_heap(_data.begin(), _data.begin() + _size);
      }

      T pop()
      {
         T d = _data.front();
         std::pop_heap(_data.begin(), _data.begin() + _size);
         _size--;
         return d;
      }

      T top()
      {
         return _data.front();
      }

      int size() const
      {
         return _size;
      }
   };

    template<class T, int fixed_size = 5>
   class fixed_size_arr_pqueue_v2
   {
      std::array<T, fixed_size> _data;
      int _size = 0;

      int parent(int i)
      {
         return (i - 1)/2;
      }

      void heapify(int i, bool downward = false)
      {
         int l = 2*i + 1;
         int r = 2*i + 2;
         int largest = 0;
         if (l < size() && _data[l] > _data[i])
            largest = l;
         else
            largest = i;

         if (r < size() && _data[r] > _data[largest])
            largest = r;   

         if (largest != i)
         {
            std::swap(_data[largest], _data[i]);
            if (!downward)
               heapify(parent(i));
            else
               heapify(largest, true);
         }
      }

      public:
      /*
      void print()
      {
         for (auto &x: _data)
            std::cout << x << " , ";
         std::cout << std::endl;
      }
      */

      void push(T &d)
      {
         if (_size == fixed_size)
         {
            //min elements in a max heap lies at leaves only. 
            auto minItr = std::min_element(begin(_data) + _size/2, end(_data));
            auto minPos {minItr - _data.begin()};
            auto min { *minItr};
            
            if (d > min)
            {
               _data.at(minPos) = d;
               if (_data[parent(minPos)] > d)
               {
                  //this is unlikely to happen in our case? as this position is gonna be a leaf?
                  heapify(minPos, true);
               }
               else
                  heapify(parent(minPos));
               //std::make_heap(begin(_data), end(_data));
            }           

            return ;
         }

         _data.at(_size++) = d;
         std::push_heap(_data.begin(), _data.begin() + _size);
      }

      T pop()
      {
         T d = _data.front();
         std::pop_heap(_data.begin(), _data.begin() + _size);
         _size--;
         return d;
      }

      T top()
      {
         return _data.front();
      }

      int size() const
      {
         return _size;
      }
   };
}

void f3()
{
   std::cout << "fixed size queue: " << std::endl;
   nonstd::fixed_size_pqueue<int> pq(5);

   for (int i =0; i < 5; i++)
      pq.push(i);

   int pqSize = pq.size();
    std::cout << "size: " << pq.size() << std::endl;
    for (int i = 0; i < pqSize; ++i)
      {
         std::cout << pq.top() << std::endl;
         pq.pop();
      }
}

void f4()
{
   std::cout << "fixed size priority_queue using std::array: \n";
   nonstd::fixed_size_arr_pqueue_v1<int, 5> pq;
   std::vector<int> v {90, 23, 99, 23, -9, 0, 23, 45, 41, 20};

   for (int i = 0; i < v.size(); ++i)
      pq.push(v[i]);

   int pqSize = pq.size();
   std::cout << "size: " << pq.size() << std::endl;
   for (int i = 0; i < pqSize; ++i)
   {
         std::cout << pq.top() << std::endl;
         pq.pop();
   }
}

void f5()
{
   std::cout << "fixed size priority_queue v2 using std::array: \n";
   nonstd::fixed_size_arr_pqueue_v2<int, 5> pq;
   std::vector<int> v {90, 23, 99, 23, -9, 0, 23, 45, 41, 20};

   for (int i = 0; i < v.size(); ++i)
      pq.push(v[i]);

   int pqSize = pq.size();
   std::cout << "size: " << pq.size() << std::endl;
   for (int i = 0; i < pqSize; ++i)
   {
         std::cout << pq.top() << std::endl;
         pq.pop();
   }
}

int main()
{
   f1();
   f2();
   f3();
   f4();
   f5();

   return 0;
}
