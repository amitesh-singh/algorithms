//using mutex, we avoid data race conditions
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mu;

void sharedPrint(string msg, int id)
{
    mu.lock();
    cout << msg << id << endl;
    mu.unlock();
}

void callingThread()
{
    for (int i = 0; i > -100; i--)
        sharedPrint(string("From thread: "), i);
}

int main()
{
    thread t(callingThread);

    for (int i = 0; i < 100; ++i)
        sharedPrint(string("From main: "), i);

    t.join();

    return 0;
}