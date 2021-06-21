#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <queue>

//implementation of semaphore using std::atomic
template<int MAX_VALUE>
class counting_semaphore
{
    std::atomic<int> val;
    public:
    counting_semaphore(int v = 0) : val(v)
    {
        if (v < 0) val = 0;
        else if (v > MAX_VALUE)
            val = MAX_VALUE;
    }

    void acquire()
    {
        while (!(val > 0))
        {
            std::this_thread::yield();
        }

        --val;
    }

    void release()
    {
        if (val < MAX_VALUE)
        {
            ++val;
        }
    }
};

using binary_semaphore = counting_semaphore<1>;
counting_semaphore<32> emptyCount(32), fillCount(0);

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
