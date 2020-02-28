#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int main()
{
   std::mutex m1, m2;
   std::thread t1([&m1, &m2]
                  {
                  cout << "1. acquiring m2\n";
                  m2.lock();
                  cout << "1. acquiring m1\n";
                  m1.lock();
                  });

   std::thread t2([&m1, &m2]
                  {
                  cout << "2. acquiring m1\n";
                  m1.lock();
                  cout << "2. acquiring m2\n";
                  m2.lock();
                  });

   t1.join();
   t2.join();

   return 0;
}
