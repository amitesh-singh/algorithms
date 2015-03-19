#include<iostream>
#include<thread>

using namespace std;

void callme()
{
    cout << __func__ << endl;
}
int main()
{
    time_t start,end;

    time(&start);
    thread t1(callme);
    t1.join();


    time(&end);

    cout << "diff: " << difftime(end,start) << " seconds" << endl;

    return 0;
}
