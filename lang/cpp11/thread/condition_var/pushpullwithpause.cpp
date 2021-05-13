#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <condition_variable>
#include <random>
#include <chrono>

/*
thread 1 ==> pushes data
thread 2 ==> process data
thread 3 ==> command to pause/resume data processing from stdin
*/

std::deque<int> data;
std::condition_variable cond, cond2;
std::mutex m, m2;
std::once_flag flag;
bool continue_flag = false;

void push_data()
{
    std::call_once(flag, [](){  srand(time(nullptr)); });
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    while (1)
    {
        std::unique_lock<std::mutex> l2(m2);
        cond2.wait(l2, [&]()->bool {return continue_flag;});
        m2.unlock();
        std::lock_guard<std::mutex> l(m);

        data.emplace_back(rand());
       
        cond.notify_one();
        m.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void pop_data()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    while (1)
    {
        std::unique_lock<std::mutex> l(m);
        cond.wait(l, [&]() -> bool {return !data.empty();});
        int d = data.front();
        data.pop_front();
        std::cout << d << std::endl;
    }

}

void process_command()
{
    int i;
    while(1)
    {
       std::cout << "enter 1 to continue, 0 to pause\n";
       
       std::cin >> i;
       std::unique_lock<std::mutex> l(m2);
      
       i == 1 ? continue_flag = true : continue_flag = false;
       std::cout << "data size = " << data.size() << std::endl;
       //m2.unlock();
       cond2.notify_one();
       //std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    auto commandT = std::thread(process_command);
    auto pushT = std::thread(push_data);
    auto popT = std::thread(pop_data);
    

    pushT.join();
    popT.join();
    commandT.join();

    return 0;
}