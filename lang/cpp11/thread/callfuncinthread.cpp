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
};
using namespace std;

int main()
{
    A aa;
    thread t(&A::domywork,&aa);
    t.join();
    return 0;
}
