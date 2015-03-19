#include<iostream>
#include<vector>

using namespace std;


template<class T>
class Callback
{
    typedef void (T::*f)();
    T *obj_;
    f f_;
    public:
    Callback(T &obj,f _f):f_(_f)
    {
        obj_ = &obj;
    }
    void execute()
    {
        obj_->f();
    }

};

class A
{
    public:
    void f()
    {
        cout << "A::f()\n";
    }
};
int main()
{
    A aa;
    Callback<A> cb(aa,&A::f);
    cb.execute();

    vector<Callback<A> > callbacks;
    callbacks.push_back(cb);


    for(int i =0;i<callbacks.size();++i)
    {
        callbacks[i].execute();
    }

    return 0;
}
