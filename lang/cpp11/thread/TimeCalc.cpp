#include<iostream>
#include<thread>
#include <ctime>

//use modern way to find the difftime
#include <chrono>

using namespace std;

void callme()
{
    cout << __func__ << endl;
}
int main()
{
    auto a = chrono::high_resolution_clock::now();
    //old way to measure time, use chrono instead
    time_t start,end;

    time(&start);
    thread t1(callme);
    t1.join();


    time(&end);

    cout << "diff: " << difftime(end,start) << " seconds" << endl;

    auto b = chrono::high_resolution_clock::now();
    //use chrono::seconds or chrono::milliseconds
    cout << "took " << chrono::duration_cast<chrono::microseconds>(b - a).count() << " microseconds" << endl;


    return 0;
}
