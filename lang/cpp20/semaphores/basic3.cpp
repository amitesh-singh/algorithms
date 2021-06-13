#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>
#include <chrono>

std::vector<int> v{};
std::binary_semaphore mainToThread(0);
std::binary_semaphore threadToMain(0);

using namespace std::string_literals;


void doWork()
{
    mainToThread.acquire();
    std::cout << "[thread]: " << " doing something\n";
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    threadToMain.release();
}

int main()
{
    std::thread t1(doWork);
    //let the thread do somework
    mainToThread.release();
    std::cout << "[main]- release()\n";
    threadToMain.acquire();
    std::cout << "[main]- got signal\n";
    t1.join();

    return 0;
}