#include <queue>
#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>

void f1()
{
   std::priority_queue<int> pq;

   for (int i = 0; i < 10; ++i)
      pq.push(i);

   for (int i = 0; i < 10; ++i)
   {
         std::cout << pq.top() << std::endl;
         pq.pop();
   }
}

void f2()
{
   std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
   for (int i = 0; i < 10; ++i)
      pq.push(i);

   for (int i = 0; i < 10; ++i)
      {
         std::cout << pq.top() << std::endl;
         pq.pop();
      }
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

int main()
{
   f1();
   f2();
   f3();
   f4();

   return 0;
}
