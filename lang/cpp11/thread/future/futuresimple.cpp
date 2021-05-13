#include <iostream>
#include <future>

int main()
{
    //or std::future<int> f1 = 
    auto f1 = std::async(std::launch::async, []() -> int {
        std::cout << "trying to finish stuff\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return 100;
    });

    std::cout << "waiting in main thread\n";

    //blocking call
    int retF1 = f1.get();
    std::cout << "value returned by thread function: " << retF1 << std::endl;

    return 0;
}