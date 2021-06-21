#include <iostream>
#include <vector>


namespace nonstd
{
   template<typename T>
   class queue
     {
        int f = 0;
        int b = -1;
        int capacity = 0;
        int count = 0;
        std::vector<T> data;

       public:
        queue(int capacity): capacity(capacity)
        {
           data.reserve(capacity);
           for(int i = 0; i < capacity; ++i)
              data.push_back(0);
        }

        bool isEmpty()
          {
             return (count == 0);
          }

        bool isFull()
          {
             return (count == capacity);
          }

        T &front()
          {
             return data[f];
          }

        T &back()
          {
             return data[b];
          }

        void push(const T &d)
          {
             if (isFull())
               {
                  std::cerr << "no more space left\n";
                  return;
               }
             
             b = (b + 1) % capacity;
             data[b] = d;
             count++;
          }

        void pop()
          {
             if (isEmpty())
               {
                  std::cerr << "queue is empty\n";
                  return;
               }

             front = (front + 1) % capacity;
             count--;
          }

        int size() const { return count; }
     };
}
int main()
{
   nonstd::queue<int> q(5);

   q.push(2);
   q.push(4);
   std::cout << "front: " << q.front() << std::endl;
   std::cout << "back: " << q.back() << std::endl;
   std::cout << "elements: " << q.size() << std::endl;
   return 0;
}
