#include<iostream>
#include<thread>
using namespace std;
//example - how to call function into a thread
class A
{
    public:
    void domywork()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void domyworkwitharg(int x)
    {
        cout << x << endl;
    }
};

void callback(int i)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

int main()
{
    A aa;
    cout << "main thread---\n";
    
    thread t(&A::domywork,&aa);
    thread t2(callback, 10);
    thread t3(&A::domyworkwitharg, &aa, 10);

    t.join();
    t2.join();
    t3.join();
    
    cout << "main thread ends..\n";

    return 0;
}
