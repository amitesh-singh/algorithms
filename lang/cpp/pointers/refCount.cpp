#include<iostream>
using namespace std;
#define F cout << __PRETTY_FUNCTION__ << endl

class Reference
{
    int mCount;
    public:
    Reference():mCount(0){}
    void inc()
    {
        ++mCount;
    }
    int dec()
    {
        --mCount;
    }
};


template<class T>
class RefObject
{
    T *mObj;
    void decRef()
    {
        if(mObj && (mObj->dec() == 0))
        {
            delete mObj;
            mObj = 0;
        }
    }
    public:
    RefObject(T *obj):mObj(obj){F;}
    RefObject():mObj(0){F;}
    RefObject(RefObject<T> &rhs)
    {
        F;
        mObj = rhs.mObj;
        if(mObj)
            mObj->inc();
    }
    RefObject<T> &operator=(RefObject<T> &rhs)
    {
        if(this == &rhs)
            return *this;
        if(rhs.mObj)
            rhs.mObj->inc();
        decRef();
        mObj = rhs.mObj;
        return *this;
    }
    ~RefObject()
    {
        F;
        decRef();
    }


};
class A:public Reference
{
};
int main()
{

    RefObject<A> ref(new A);
    RefObject<A> ref1(ref);
    ref1 = ref;
    RefObject<A> ref2;


    return 0;
}
