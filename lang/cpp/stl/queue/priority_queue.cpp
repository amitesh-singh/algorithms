#include <queue>
#include <iostream>
#include <vector>
#include <list>

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
}

void f3()
{
   std::cout << "fixed size queue: " << std::endl;
   nonstd::fixed_size_pqueue<int> pq(5);

   for (int i =0; i < 10; i++)
      pq.push(i);

    std::cout << "size: " << pq.size() << std::endl;
    for (int i = 0; i < 5; ++i)
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

   return 0;
}
