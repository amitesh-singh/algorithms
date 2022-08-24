#include <future>
#include <thread>
#include <iostream>

using namespace std;

int main()
{
    cout << "main thread id " << this_thread::get_id() << endl;

    // it seems async uses thread pool
    future<int> f1 = async(launch::async, [](){
        cout << "future run on thread " << this_thread::get_id() << endl;
        return 1;
    });


    future<int> f2 = async(launch::async, [](){
        cout << "future run on thread " << this_thread::get_id() << endl;
        return 1;
    });

    future<int> f3 = async(launch::async, [](){
        cout << "future run on thread " << this_thread::get_id() << endl;
        return 1;
    });

    f1.get(); 
    f2.get();
    f3.get();

    cin.ignore();

    return 0;
}
