#include<iostream>
#include<cstdio>
using namespace std;


struct FILE_ptr
{
    private:
    FILE *f;
    public:
    FILE_ptr(const char *fn,const char *io)
    {
        f = fopen(fn,io);
    }
    FILE_ptr(FILE *pp):f(pp)
    {
    }
    ~FILE_ptr()
    {
        if(f)
            fclose(f);
    }

    operator FILE *(){return f;}
};
void f()
{
    FILE_ptr f("ok","r");
    //use f
}
int main()
{
    try
    {
        f();
    }
    catch(...)
    {
        cerr << "Exception catched\n";
    }
    
    return 0;
}
