#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <ctime>
#include <chrono>
#include <stack>

namespace threadsafe
{
    template<class T>
    class stack
    {
        //mutable for const mem functions
        mutable std::mutex _mu;
        std::condition_variable _cond;
        std::stack<T> _data;
        public:
        void push(T &data)
        {
            std::lock_guard<std::mutex> locker(_mu);
            _data.push(data);
            _cond.notify_all();
        }

        T top() const
        {
            std::lock_guard<std::mutex> locker(_mu);
            return _data.top();
        }

        T pop()
        {
            int ret;
            std::unique_lock<std::mutex> locker(_mu);
            _cond.wait(locker, [this] () -> bool { return !_data.empty();});
            ret = _data.top();
            _data.pop();
            return ret;
        }

        int size() const
        {
            std::lock_guard<std::mutex> locker(_mu);
            return _data.size();
        }
    };
}

void pushData(threadsafe::stack<int> &s)
{
    int val;
    while (1)
    {
        val = rand();
        s.push(val);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void pollData(threadsafe::stack<int> &s)
{
    int val;
    while(true)
    {
        val = s.pop();
        std::cout << "pollData: " << val << std::endl;
    }
}

int main()
{
    srand(time(nullptr));
    threadsafe::stack<int> s;
    std::thread dataPusher(pushData, std::ref(s));
    std::thread dataPoller(pollData, std::ref(s));

    dataPusher.detach();
    dataPoller.detach();

    while (1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}