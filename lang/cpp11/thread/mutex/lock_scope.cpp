#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// -std=c++17
// unique_lock is deprecated in cpp17

int main()
{
    std::mutex m1, m2;
    std::thread t1(
        [&m1, &m2]() {
            //used for multiple mutexes
            std::scoped_lock<std::mutex, std::mutex> l(m1, m2);
            std::cout << "call me\n";
        }
    );

    t1.join();

    return 0;
}