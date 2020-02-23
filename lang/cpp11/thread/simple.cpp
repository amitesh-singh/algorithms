#include <iostream>
#include <thread>

using namespace std; 

void callingThread()
{
    cout << "Callme when you get time\n";
}

int main()
{
    thread t1(callingThread);
    // t1.join(); main thread waits for t1 to finish 
    t1.detach(); // thread is on its own -- daemon process

    //after detaching or joininig, we can't rejoin again

    //t1.join(); //this  will crash 
    // to avoid this, use if (t1.joinable()) check

    if (t1.joinable())
        t1.join(); //it won't  get called though.
    return 0;
}