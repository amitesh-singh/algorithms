#include <iostream>

using namespace std;

template<class T>
class callback
{
    using f = void (T::*)();

    f _f;
    T *_obj;
    public:
    callback(T &obj, f f1)
    {
        _obj = &obj;
        _f = f1;
    }

    void execute()
    {
        _f();
    }
};

class A
{
    public:
    void _f()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main()
{
    A aa;
    callback<A> c(aa, A::_f);

    c.execute();
    
    return 0;
}