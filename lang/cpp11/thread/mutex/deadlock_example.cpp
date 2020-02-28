#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mu, mu2;
//use of multiple mutexes and if there is inconsistency in ordering, it
//might results into deadlock.

void callingThread()
{
   //notice the ordering of locking of mutexes
   std::unique_lock<std::mutex> locker(mu);
   std::this_thread::sleep_for(std::chrono::milliseconds(100));
   std::unique_lock<std::mutex> locker2(mu2);
   for (int i = 0; i < 1000; i++)
     cout << "From thread1: " << i << endl;
}

void callingThread2()
{
   //notice the ordering of locking of mutexes
   std::unique_lock<std::mutex> locker2(mu2);
   std::unique_lock<std::mutex> locker(mu);
   for (int i = 0; i < 1000; i++)
     cout << "From Thread2: " << i << endl;
}

int main()
{
   thread t1(callingThread);
   thread t2(callingThread2);
   t1.join();
   t2.join();

   return 0;
}
