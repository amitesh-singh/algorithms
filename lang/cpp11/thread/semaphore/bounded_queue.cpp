
#include <thread>
#include "semaphore.h"
#include <iostream>
#include <queue>

template<typename T, int BUFFER_SIZE>
class bounded_queue
{
   nonstd::counting_semaphore<BUFFER_SIZE> fillCount = 0;
   nonstd::counting_semaphore<BUFFER_SIZE> emptyCount = BUFFER_SIZE;
   std::mutex items_mutex;
   std::queue<T> data;
  public:
   void push(const T &d)
     {
        emptyCount.acquire();
        items_mutex.lock();
        data.push(d);
        items_mutex.unlock();
        fillCount.release();
     }

   T pop()
     {
        T ret;
        fillCount.acquire();
        items_mutex.lock();
        ret = data.front();
        data.pop();

        items_mutex.unlock();
        emptyCount.release();
        return ret;
     }

};


bounded_queue<int, 32> seats;
int i = 0;
void producer()
{
   while(1)
     {
        i++;
        seats.push(i);
        std::cout << "pushed: " << i << std::endl;
     }
}

void consumer()
{
   while (1)
     {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        int seat = seats.pop();
        std::cout << "pop: " << seat <<std::endl;
     }
}

int main()
{
   std::thread t1 (producer);
   std::thread t2 (consumer);
   std::thread t3 (consumer);

   t1.join();
   t2.join();
   t3.join();
   return 0;
}
