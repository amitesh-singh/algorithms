#include<iostream>
#include<thread>
using namespace std;

void callingthreads(int tid)
{
    cout << "calling thread no: " << tid << endl;
}

static const int numThreads = 10;

int main()
{
    thread t[numThreads];
    for(int i =0;i<numThreads;i++)
    {
        t[i] = thread(callingthreads,i);
    }
    cout << "launching threads from the main() " << endl;
    for(int i =0;i<numThreads;i++)
    {
        t[i].join();
    }

    return 0;
}
