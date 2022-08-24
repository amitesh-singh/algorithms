#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std::chrono_literals;
int main()
{
   //creating a temproary future object here since std::async returns a future object
   // and in ~future() { get(); //blocking }
   std::async(std::launch::async, []()->void {
              std::cout << "started the work\n";
              std::this_thread::sleep_for(10s);
              std::cout << "work is done\n";
              });

   std::cout << "main thread work\n";
   return 0;
}
