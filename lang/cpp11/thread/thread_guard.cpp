#include<iostream>
#include<thread>


using namespace std;
#define F cout << __LINE__ << ":" << __PRETTY_FUNCTION__ <<endl;

struct thread_gaurd
{
    thread_gaurd(thread &t):_t(t)
    {
        F;
    }
    ~thread_gaurd()
    {
        if(_t.joinable())
        {
            _t.join();
        }
        F;
    }
    thread_gaurd(thread_gaurd const &) =delete;
    thread_gaurd &operator=(thread_gaurd const &)= delete;
    private:
    thread &_t;
};
class func
{
    int &_a;
    public:
    func(int &a):_a(a)
    {
        F;
    }
    void operator()()
    {
        F;
    }

};
void f()
{
    int local_var = 10;
    func f2(local_var);
    
    thread t(f2);
    thread_gaurd gg(t);
}
int main()
{
    int i =11;
    func f1 =func(i);
    thread t1(f1);
    thread_gaurd gg(t1);
    f();
    return 0;
}
