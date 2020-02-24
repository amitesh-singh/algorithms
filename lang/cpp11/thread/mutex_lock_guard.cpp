#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex mu;

void sharedPrint(string msg, int i)
{
   std::lock_guard<std::mutex> guard(mu); //RAII
   //when guard goes out of scope, calls mu.unlock() automatically. don't use mu at all, can't lock or unlock..
   cout << msg << i << endl;
}

void sharedPrint2(string msg, int i)
{
   std::unique_lock<std::mutex> locker(mu); //we can do manual lock and unlock, useful if we plan to use it more
   // more resource heavy though.
   cout << msg << i << endl;
}

void callingThread()
{
   for (int i = 0; i > -100; --i)
     sharedPrint("From Thread: ", i);
}

void callingThread2()
{
   for (int i = 0; i > -100; --i)
     sharedPrint2("From Thread2: ", i);
}

int main()
{
   thread t(callingThread);

   for (int i = 0; i < 100; ++i)
     sharedPrint("From main: ", i);

   t.join();

   thread t2(callingThread2);
   for (int i = 0; i < 200; ++i)
     sharedPrint2("From main: ", i);
   t2.join();

   return 0;
}
