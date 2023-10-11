#include <barrier>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

/*
There are two differences between a std::latch and a std::barrier. A std::latch is useful
 for managing one task by multiple threads; 
a std::barrier helps manage repeated tasks by multiple threads.
 Additionally, a std::barrier enables you to execute a 
function in the so-called completion step. The completion 
step is the state when the counter becomes zero.
*/

/*
the key difference between arrive_and_wait() and arrive_and_drop() is in how threads handle synchronization. 
arrive_and_wait() blocks the calling thread until all threads arrive at the barrier,
 while arrive_and_drop() allows the calling thread to continue independently after signaling its arrival. 
The choice between the two methods depends on your specific synchronization needs in your multithreaded application.
*/
//create a barrier for 6 threads
std::barrier work_done(6);
std::mutex cout_mutex;

void sync_cout(const std::string &s)
{
    std::lock_guard<std::mutex> guard(cout_mutex);
    std::cout << s << std::endl;
}

class FullTimeWorker
{
public:
    FullTimeWorker(const std::string &name): name(name) {}
    void operator() ()
    {
        sync_cout(name + ": Morning work is done");
        work_done.arrive_and_wait(); //we want everyone to finish their morning work
        sync_cout(name + ": Evening work is done");
        work_done.arrive_and_wait();
    }
private:
    std::string name;
};

class PartTimeWorker
{
public:
    PartTimeWorker(const std::string &name): name(name) {}

    void operator() ()
    {
        sync_cout(name + ": Morning work is done");
        work_done.arrive_and_drop();
    }

private:
    std::string name;
};

int main()
{
    auto fulltime_workers = { "ami", "avi", "aarav" };
    auto parttime_workers = { "pooja", "love1", "love2" };
    
    std::vector<std::jthread> threads;
    std::vector<FullTimeWorker> f_workers;
    std::vector<PartTimeWorker> p_workers;

    threads.reserve(std::size(fulltime_workers) + std::size(parttime_workers));
    f_workers.reserve(std::size(fulltime_workers));
    p_workers.reserve(std::size(parttime_workers));

    for (auto &worker: fulltime_workers) {
        f_workers.emplace_back(FullTimeWorker(worker));
    }

    for (auto &worker: parttime_workers) {
        p_workers.emplace_back(PartTimeWorker(worker));
    }

    for (auto &worker: f_workers) {
        threads.emplace_back(worker);
    }
    for (auto &worker: p_workers) {
        threads.emplace_back(worker);
    }

    return 0;
}