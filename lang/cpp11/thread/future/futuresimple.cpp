#include <iostream>
#include <future>

/*
 *std::launch::async indicates that the function call must be run on its own (new) thread. (Take user @T.C.'s comment into account).
std::launch::deferred indicates that the function call is to be deferred until either wait() or get() is called on the future. Ownership of the future can be transferred to another thread before this happens.
std::launch::async | std::launch::deferred indicates that the implementation may choose. This is the default option (when you don't specify one yourself). It can decide to run synchronously.
 *
 * */
int main()
{
    //or std::future<int> f1 = 
    // two options std::launch::async or std::launch::deferred
    //  std::launch::aysnc -> run the function call in it's own thread.
    //  std::launch::deferred indicates that the function call is to be deferred until either wait() or get() is called on the future. Ownership of the future can be transferred to another thread before this happens.
    //  std::launch::async | std::launch::deferred indicates that the implementation may choose. This is the default option (when you don't specify one yourself). It can decide to run synchronously.
    //
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
