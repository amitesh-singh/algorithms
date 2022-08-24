#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <future>


using namespace std::chrono_literals;
//we can use promise and future as signal
// we just want to synchronise the point in time when the execution starts with std::promise and std::future, and we don’t really want to send an object. In this case we can use the wait member function.



int main()
{
   std::promise<void> p;
   auto future = p.get_future();

   auto t = std::thread([](std::future<void> f)->void {
                        std::cout << "starting thread\n";
                        f.wait(); //wait from the main thread.
                        std::cout << "doing the work\n";
                        }, std::move(future));

   std::cout << "doing some work in main thread..preparing data for the thread\n";
   std::this_thread::sleep_for(5s);
   //this starts the thread
   p.set_value();

   t.join();

   return 0;
}
