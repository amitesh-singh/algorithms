#include <iostream>
#include <thread>

using namespace std; 

void callingThread()
{
    cout << "Callme when you get time\n";
    cout << "inside thread function: " << std::this_thread::get_id() << endl;
}

class Ftor
{
    public:
    void operator()(string &msg)
    {
        cout << "msg from main: " << msg << endl;
        msg = "msg from thread\n";
    }
};

int main()
{
    cout << "main thread " << std::this_thread::get_id() << endl;
    //this gives the information on how many threads i can run to
    // avoid over subscription
    cout << "how many threads are supported? " << std::thread::hardware_concurrency() << endl;
    thread t1(callingThread);
    cout << "child thread id: " << t1.get_id() << endl;

    t1.join(); // main thread waits for t1 to finish 
    //t1.detach(); // thread is on its own -- daemon process
    //after detaching or joininig, we can't rejoin again

    //t1.join(); //this  will crash 
    // to avoid this, use if (t1.joinable()) check

    if (t1.joinable())
        t1.join(); //it won't  get called though.

    //msg is getting shared among main thread and thread 1
    string msg = "Hello buddy";
    //pass msg as reference to thread
    // or we could pass good old pointers
    thread t2((Ftor()), std::ref(msg));
    t2.join();

    cout << "msg from thread: " << msg << endl;

    return 0;
}