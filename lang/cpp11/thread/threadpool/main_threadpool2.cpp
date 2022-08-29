#include "threadpool2.h"
#include <chrono>
using namespace std::chrono_literals;

int main()
{
   nonstd::threadpool tp(2);
   tp.start();

   tp.addJob([]()->void {std::cout << "hello world\n"; });
   auto f = tp.addJob([]()->void { std::cout << "2nd job\n"; std::this_thread::sleep_for(10s); return; });
   std::cout << "2nd thread output:\n ";
   f.get();
   return 0;
}
