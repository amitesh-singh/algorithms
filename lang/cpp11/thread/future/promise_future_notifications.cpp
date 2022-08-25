#include <iostream>
#include <future>
#include <thread>
#include <chrono>

//we could use promise/future as events
using namespace std::chrono_literals;


void waitForWork(std::future<void> &&f)
{
   std::cout << "waiting for the work \n";
   f.wait();
   std::cout << "process the data \n";
}

void prepareData(std::promise<void> &&p)
{
   std::cout << "preparing data\n";
   std::this_thread::sleep_for(10s);
   std::cout << "data preparation is completed\n";
   p.set_value();
}

int main()
{
   std::promise<void> p;
   auto f = p.get_future();

   auto t1 = std::thread(waitForWork, std::move(f));
   auto t2 = std::thread(prepareData, std::move(p));
   t1.join();
   t2.join();
   return 0;
}
