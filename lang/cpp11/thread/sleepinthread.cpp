
#include <iostream>
#include <thread>
#include <chrono>

void func()
{
    while (1)
    {
        //1s timeout
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "thread called.\n";
    }

}

int main()
{
    std::thread t1(func);
    t1.detach();
    while (1)
      {
         //gonna run forever
         //sleep for reducing cpu cycles
         std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
    return 0;
}
