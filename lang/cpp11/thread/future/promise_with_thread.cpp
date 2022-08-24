#include <iostream>
#include <future>

void f(std::promise<int> &promise)
{
    std::cout << "inside thread:\n";
    std::this_thread::sleep_for(std::chrono::seconds(4));
    promise.set_value(100);
}

int main()
{
    std::promise<int> promise;
    auto future = promise.get_future();

    auto t1 = std::thread(f, std::ref(promise));
    std::cout << "value from future: " << future.get() <<  std::endl;
    
    t1.join();
    std::cout << "thread exit\n";
    return 0;
}