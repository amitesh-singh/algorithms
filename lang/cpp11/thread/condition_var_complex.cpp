#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>

std::mutex mu;
std::condition_variable cond;
std::deque<int> d;

void f()
{
    int count = 10;
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

void g()
{
    int data = 0;
    while (data != 1)
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
    std::thread t1(f);
    std::thread t2(g);

    t1.join();
    t2.join();

    return 0;
}