#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <condition_variable>

namespace threadsafe
{
    class stack
    {
        std::vector<int> _data; 
        mutable std::mutex _mu;

        public:

        void push(int d)
        {
            std::lock_guard<std::mutex> locker(_mu);
            _data.push_back(d);
        }

        int pop()
        {
            std::lock_guard<std::mutex> locker(_mu);
            int ret = _data.back();
            _data.erase(_data.end() - 1);
            return ret;
        }

        int top() const
        {
            std::lock_guard<std::mutex> locker(_mu);
            return _data.back();
        }

        int size() const
        {
            std::lock_guard<std::mutex> locker(_mu);
            return _data.size();
        }
    };
}

std::mutex mu;

void process(threadsafe::stack &s, std::string threadname)
{
   // int d = s.top();
   // s.pop();
    int d = s.pop();

    std::lock_guard<std::mutex> locker(mu);
    std::cout << threadname << ": " << d << std::endl;
}

int main()
{
    threadsafe::stack s;
    for (int i = 0; i < 10; ++i)
        s.push(i);
    std::cout << "stack size: " << s.size() << std::endl;
    int initialSize = s.size();
    while (initialSize > 0)
    {
        std::thread t1, t2;
        if (initialSize > 1)
        {
            t1 = std::move(std::thread(process, std::ref(s), "Thread 1"));
            initialSize--;
        }
       
        t2 = std::move(std::thread(process, std::ref(s), "Thread 2"));
        initialSize--;
      
        if (t1.joinable())
            t1.join();
        
        t2.join();
    }

    return 0;
}
