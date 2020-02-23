#include<iostream>
#include<thread>
//http://www.devx.com/SpecialReports/Article/38883
//how to compile
// g++ -std=c++0x -pthread file.cpp
//http://solarianprogrammer.com/2011/12/16/cpp-11-thread-tutorial/
void do_work()
{
    std::cout << "My work\n";
}

class A
{
    public:
    A()
    {
    }
    void operator()()
    {
        std::cout << __func__ << std::endl;
    }
};

int main()
{
    A aa;
    std::thread t1(do_work);
    t1.join(); //main thread waits t1 to finish

    //this will call aa.operator()
    //but this one will call copy constructor.. so many calls..
    std::thread t2(aa);
    //use std::thread t2(std::ref(aa)); //instead
    t2.join(); //main thread waits for t2 to finish
    return 0;
}
