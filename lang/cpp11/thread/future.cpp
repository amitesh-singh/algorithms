#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <future>

using namespace std;

int main()
{
   auto f = []() -> int {

        cout << "I am in a thread\n";
        std::this_thread::sleep_for(std::chrono::seconds(4));
        return 10;

     };

   auto future = std::async(std::launch::async, f);
   cout << "Waiting for thread to do the job in main thread\n";
   //blocking call
   cout << future.get() << endl;

   //lets loop in main thread.
   auto timeout = std::chrono::milliseconds(10);

   future = std::async(std::launch::async, f);

   auto future2 = std::async(std::launch::async, []() -> int {

                             std::this_thread::sleep_for(std::chrono::seconds(10));
                             return 11;

                             });
   while (future.valid() || future2.valid())
     {
        if (future.valid() && future.wait_for(timeout) == std::future_status::ready)
        {
           cout << "Task1 is done: " << future.get() << "\n";
        }
        if (future2.valid() && future2.wait_for(timeout) == std::future_status::ready)
        {
           cout << "Task2 is done: " << future2.get() << "\n";
        }
     }

   return 0;
}
