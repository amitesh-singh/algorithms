#include<iostream>
#include<thread>

using namespace std;

void call_from_thread()
{
   cout << "another thread" << endl;
}

int main()
{
   std::thread t(call_from_thread);

   cout << "Launch from main()" << endl;

   //join the threads with the main thread.
   t.join();

   return 0;
}
