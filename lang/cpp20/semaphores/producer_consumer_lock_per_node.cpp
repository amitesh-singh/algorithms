#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>
#include <chrono>
#include <queue>
#include <deque>
#include <mutex>

using namespace std::chrono_literals;

//refer to wiki: search "producer-consumer problem"
//https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem
std::counting_semaphore<32> emptyCount(32); //32 is the size of queue buffer
std::counting_semaphore<32> fillCount(0); //0, not acquired state.
struct node {
     int data;
     std::mutex m;
     node (int d) : data(d) {}
};
std::deque<node *> q;
std::mutex datamutex;
int i = 0;

bool handle_special_push_cond(std::deque<node *> &q)
{
   std::lock_guard<std::mutex> l(datamutex);
   if (q.empty() || q.size() == 1)
     {
        q.push_back(new node(++i));
        std::cout << "pushed: " << i << " ";
        return true;
     }
   else return false;
}

bool handle_special_pop_cond(std::deque<node *> &q)
{
   std::lock_guard<std::mutex> l(datamutex);
   if (q.size() == 1)
     {
        node *front = q.front();
        q.pop_front();
        std::cout << "popped: " << front->data << " ";
        delete front;
        return true;
     }
   else return false;
}

void producer(const char *workername, const std::chrono::seconds timeout)
{
   while (1)
     {
        emptyCount.acquire();
        if (!handle_special_push_cond(q))
          {
             q.back()->m.lock();
             // get the adjacent to end node.
             node *adj_back = *(std::prev(q.end(), 2));
             node *back = q.back();
             adj_back->m.lock();

             q.push_back(new node(++i));
             std::cout << "pushed: " << i << " ";

             adj_back->m.unlock();
             back->m.unlock();
          }

        std::cout << workername << ": size:" << q.size() << std::endl;

        fillCount.release();
        std::this_thread::sleep_for(timeout);
     }
}

void consumer(const char  *workername, const std::chrono::seconds timeout)
{
   while (1)
     {
        fillCount.acquire();

        if (!handle_special_pop_cond(q))
          {
             q.front()->m.lock();
             node *front = q.front();
             node *adj_front = *(std::next(q.begin(), 1));
             adj_front->m.lock();

             std::cout << workername << ": " << front->data << std::endl;
             q.pop_front();
             std::cout << "popped: " << front->data << " ";

             adj_front->m.unlock();

             front->m.unlock();
             delete front;
          }
        std::cout << workername << ":size: " << q.size() << std::endl;

        emptyCount.release();

        std::this_thread::sleep_for(timeout);
     }
}

int main()
{
   std::cout << typeid(1s).name();
   std::cout << "\n\n";
   std::thread t1(producer, std::ref("producer 1"), 1s);
   std::thread t2(producer, std::ref("lazy producer =====> 2"), 5s);
   std::thread t3(consumer, std::ref("consumer 1"), 3s);
   std::thread t4(consumer, std::ref("Lazy Consumer ******* 2"), 10s);

   t1.join();
   t2.join();
   t3.join();
   t4.join();


   return 0;
}
