#include<iostream>
#include<exception>
using namespace std;
#define F cout << __PRETTY_FUNCTION__ << endl
#define FORMAT_(type) FORMAT_ ##type
template<class T,T low,T high>
class Range
{
    T i;
    public:
    Range(T j):i(j)
    {
        try 
        {
            if(i < low || i > high)
                throw exception();
        }
        catch(std::exception &e)
        {
            cout << e.what() << "\n";
        }
    }
    //called when T = Range<T>;
    operator T() 
    { 
        F;

        return i;
    };
};
void FORMAT_(integer)()
{
    F;
}
int f(Range<int,10,12> r)
{
    return r;
}
int main()
{
    f(11);

    f(-11);
    Range<int,10,20> r(11);
    int k = r;
    //r = 10;
    FORMAT_(integer)();

    return 0;
}
