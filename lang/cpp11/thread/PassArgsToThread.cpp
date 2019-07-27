#include<iostream>
#include<thread>
//how to pass args to a thread
using namespace std;

void func(int a,string s)
{
    cout << a << ":" << s <<endl;
}

int main()
{
    string google("ok");

    thread t(func, 10, google);
    t.join();

    return 0;
}
