#include <iostream>
#include <mutex> //for call_once and once_flag
#include <thread>

namespace threadsafe
{
    class Singleton
    {
        static Singleton *_instance;
        
        public:
        static Singleton *getInstance()
        {
            static std::once_flag flag;
            std::call_once(flag, [&]() { _instance = new Singleton();});

            return _instance;
        }
    };
}

threadsafe::Singleton *threadsafe::Singleton::_instance = nullptr;

std::mutex mu;
void func(std::string s)
{
    std::lock_guard<std::mutex> locker(mu);
    std::cout << s << " : " << threadsafe::Singleton::getInstance() << std::endl;
}

int main()
{
    std::thread t1(func, "thread 1");    
    std::thread t2(func, "thread 2");
    
    t1.join();
    t2.join();

    func("main thread");
    return 0;
}