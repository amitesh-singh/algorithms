#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

std::mutex mu;
std::condition_variable cond;

void callingThread()
{
   cout << __PRETTY_FUNCTION__ << endl;
   while (1)
   {
      std::unique_lock<mutex> locker(mu);
      cout << "\nThread1: notifying" << endl;
      locker.unlock();
      //call notify outside mutex lock
      cond.notify_one();
      std::this_thread::sleep_for(std::chrono::seconds(1));

   }
}

void callingThread2()
{
   cout << __PRETTY_FUNCTION__ << endl;

   while (1)
   {
      std::unique_lock<mutex> locker(mu);
      //call wait inside mutex lock
      cond.wait(locker);
      cout << "Thread2: Notified" <<  endl;
      locker.unlock();

      std::this_thread::sleep_for(std::chrono::milliseconds(100));
   }
}

int main()
{
   std::thread t1(callingThread);
   std::thread t2(callingThread2);

   t1.join();
   t2.join();

   return 0;
}

