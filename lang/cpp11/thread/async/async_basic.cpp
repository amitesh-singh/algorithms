#include <thread>
#include <future>
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
   std::future<void> f = std::async(std::launch::async, []()->void {
                                        std::cout << "done with the work\n";
                                     });

   f.get(); //blocking call.
            //
   //use auto instead to deduce the type

   auto f2 = std::async(std::launch::async, []()->int {
                        std::this_thread::sleep_for(10s);

                        return 10;
                        });

   //f2.get is blocking here
   std::cout << f2.get() << '\n';



   return 0;
}
