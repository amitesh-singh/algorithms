#include <thread>
#include <iostream>
#include <chrono>
#include <atomic>

using namespace std::string_literals;
class A
{
    std::jthread t;
    public:
    A()
    {
        t = std::jthread([this](std::stop_token st) {
            while (!st.stop_requested())
            {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "..\n";
            }
        });
    }
    ~A()
    {
       //no need to call
       //t.request_stop();
       // or join the thread
       // if (t.joinable()) {
       //   t.join();
       // }
    }
};

int main()
{
    A aa;
    std::this_thread::sleep_for(std::chrono::seconds(4));
    return 0;
}
