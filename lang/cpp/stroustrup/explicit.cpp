#include<iostream>
using namespace std;
class A
{
    public:
    A()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};
int main()
{
    A aa();
   
    return 0;
}
