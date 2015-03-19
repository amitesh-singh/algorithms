#include<iostream>
using namespace std;
#include<stdexcept>

void handleException() try
{
    throw;
}
catch(std::exception &e)
{
    cout << e.what();
}


void f()
{
    try
    {
        throw std::logic_error("throwing something\n");
    }
    catch(...)
    {
        handleException();
    }
}


int main()
{
    f();
    return 0;
}
