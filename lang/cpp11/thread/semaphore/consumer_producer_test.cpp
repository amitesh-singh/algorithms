#include "semaphore.h"
#include <iostream>
#include <queue>

nonstd::counting_semaphore<32> emptyCount(32), fillCount(0);

std::queue<int> q;
int i = 0;
void producerWork()
{
    while (1)
    {
       std::this_thread::sleep_for(std::chrono::seconds(1));
        emptyCount.acquire();
        ++i;
        q.push(i);
        std::cout << "pushing: " << i << " " << std::endl;
        fillCount.release();
    }

}

void consumerWork()
{
    while (1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        fillCount.acquire();
        int r = q.front();
        q.pop();
        std::cout << "pop: " << r << std::endl;
        emptyCount.release();
    }

}

int main()
{
    std::thread t1(producerWork);
    std::thread t2(consumerWork);
    emptyCount.release();

    t1.join();
    t2.join();
    return 0;
}
