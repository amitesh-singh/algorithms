//template as a qualifier example.
// 

#include<iostream>

using namespace std;
#define F cout << __PRETTY_FUNCTION__ << endl
using namespace std;
class Memory
{
    public:
    template<class T> 
    T *get_new()
    {
        T *t = new T;
        return t;
    }
    template<class T>
    void release(T &t)
    {
        delete t;
    }
};
template<class Alloc,class type>
void f(Alloc &m)
{
    //template as a qualifier
    type *p1 = m.template get_new<type>();
    m.release(p1);
}
int main()
{
    Memory m;
    f<Memory,int>(m);
    return 0;
}
