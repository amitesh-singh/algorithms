#include <iostream>
#include <future>
#include <chrono>
#include <thread>

using namespace std::string_literals;
//you know this for std::this_thread::chrono_literals
using namespace std::chrono_literals;

std::string f(std::string token)
{
    std::string data = "fetched data: " + token;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::this_thread::sleep_for(3s);
    return data;
}

int main()
{
    std::packaged_task<std::string(std::string)> task(f);
    auto future = task.get_future();

    std::cout << "running task in main thread: " << std::endl;
    task("main");

    std::cout << "got data in main thread: " << future.get() << std::endl;

    //// let's run the task in other thread.

    std::packaged_task<std::string(std::string)> task2(f);
    auto future2 = task2.get_future();

    //task is not copyable, so move it to a different thread
    std::thread t1(std::move(task2), "thread 1");
    std::cout << "got data in main thread: " << future2.get() << std::endl;
    
    t1.join();
    
    return 0;
}
