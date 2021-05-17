#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>
#include <chrono>

std::vector<int> v{};

//in c++20, it is defined as alias
// using binary_semaphore = std::counting_semaphore<1>
//initial value is 0, so no acquire state
using binary_semaphore = std::counting_semaphore<1>;
binary_semaphore prepareSignal(0);

void prepareWork()
{
   std::cout << "Sender: Data is getting prepared" << std::endl;
   v.insert(v.end(), {1, 2, 3, 4});
   std::this_thread::sleep_for(std::chrono::seconds(3));
   std::cout << "Sender: Data Prepared. " << std::endl;
   prepareSignal.release();
}

void completeWork()
{
   std::cout << "Waiter: Waiting for data. " << "\n";
   prepareSignal.acquire();
   v[2] = 2;
   std::cout << " complete the work\n";
   for(auto &&i: v) std::cout << i << " ";
   std::cout << std::endl;
}

int main()
{
   std::jthread t1(prepareWork);
   std::jthread t2(completeWork);

   return 0;
}
