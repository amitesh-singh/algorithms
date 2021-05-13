#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <chrono>
#include <functional>

std::vector<int> timeouts = {1, 2, 3, 2, 1};
std::vector<int> result;
std::mutex m;

void dowork(int thread_no)
{
    //the below function replicate the time taken by async stuff
    std::this_thread::sleep_for(std::chrono::seconds(timeouts[thread_no]));
    //before committing the data, lock it.
    std::lock_guard<std::mutex> lock(m);
    result.push_back(thread_no);
}

int main()
{
    std::vector<std::future<void>> futures;

    int threads_count = timeouts.size();
    
    //processing all data
    std::cout << "processing all data" << std::endl;

    for (int i = 0; i < threads_count; ++i)
    {
        std::cout << "calling all async: " << i << std::endl;
        futures.emplace_back(std::async(std::launch::async, dowork, i));
    }
    std::cout << "Waiting in main " << std::endl;
    //code which checks if all future tasks are completed.
    bool alltasks_completed;
    while (1)
    {
        alltasks_completed = true;
        for (auto &f: futures)
            {
                if (f.valid() && !(f.wait_for(std::chrono::milliseconds(100)) == std::future_status::ready))
                { 
                    alltasks_completed = false;
                    std::cout << "task is not completed yet\n";
                    break;
                }
            }
        if (alltasks_completed) break;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    
    if (alltasks_completed)
    {
        for (auto &&r: result)
        {
            std::cout << r << ", " << std::endl;
        }
    }

    return 0;
}