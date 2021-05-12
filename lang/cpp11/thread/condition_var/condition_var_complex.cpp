#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>

std::mutex mu;
std::condition_variable cond;
std::deque<int> d;
int count = 10;

void push_data()
{
    //int count = 10;
    while (count > 0)
    {
        std::unique_lock<std::mutex> locker(mu);
        d.push_back(count);
        --count;
        locker.unlock();

        std::this_thread::sleep_for(std::chrono::seconds(1));
        cond.notify_one();
    }
}

void pop_data()
{
    int data = 0;
    while (count > 0)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, [&]() -> bool { return !d.empty(); });
        data = d.front();
        d.pop_back();
        locker.unlock();

        std::cout << "data: " << data << std::endl;
    }
}

int main()
{
    std::thread t1(push_data);
    std::thread t2(pop_data);

    t1.join();
    t2.join();

    return 0;
}