#include<thread>
#include<iostream>
using namespace std;
#define F cout << __LINE__ << " " << __PRETTY_FUNCTION__ << endl
class func
{
    public:
    func()
    {
        F;
        
    }
    func(const func &obj)
    {
        F;
    }
    
    ~func()
    {
        F;
    }
    void operator()()
    {
        F;
    }
};
int main()
{
    func f;
    cout << "before\n";
    //without std::ref, 4 constructor and destructor calls. bad thing, huh!? :P
    thread t(std::ref(f));
    //wait for thread to finish
    t.join();
    return 0;
}
