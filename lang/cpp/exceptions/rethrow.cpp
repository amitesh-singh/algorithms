#include<iostream>
using namespace std;


void f()
{
    try
    {
        throw;
    }
    catch(...)
    {

    }
}
int main()
{
    try
    {
        f();
    }
    catch(...)
    {
    }


    return 0;
}
