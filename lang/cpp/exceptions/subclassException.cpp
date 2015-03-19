#include<iostream>
using namespace std;

class A
{
    public:
    A()
    {
        throw "A";
    }
};
class B :public A
{
    public:
    B() try:A()
    {
    }
    catch(const char *str)
    {
        cout << str << endl;
    }
    catch(...)
    {
        cout << "subclass initialization is failed\n";
    }
};

int main()
{
    B bb;

    return 0;
}
