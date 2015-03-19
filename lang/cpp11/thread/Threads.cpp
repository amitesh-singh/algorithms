#include<iostream>
#include<thread>

using namespace std;


void call_from_thread()
{
    cout << __func__ << endl;
}
int main()
{
    thread t[10];
    for(int i =0;i<10;i++)
        t[i] = std::thread(call_from_thread);

    cout << "Launch from main()" << endl;
    //join the threads with the main thread.
    for(int i =0;i<10;i++)
        t[i].join();



    return 0;
}
