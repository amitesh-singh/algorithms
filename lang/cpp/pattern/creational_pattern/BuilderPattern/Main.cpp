#include<iostream>
#define F cout << __LINE__ << ":" << __PRETTY_FUNCTION__ << endl
using namespace std;
class Builder
{
    public:
    virtual void BuildPart() = 0;
};
class C1Builder:public Builder
{
    public:
    void BuildPart()
    {
        F;
    }
};

class C2Builder:public Builder
{
    public:
    void BuildPart()
    {
        F;
    }
};
class Director
{
    Builder *_builder;
    public:
    enum Type {type1,type2};
    Director()
    {
    }
    Builder * Construct(Type type)
    {
        if(type == type1)
            _builder = new C1Builder();
        else if(type == type2)
            _builder = new C2Builder();
        return _builder;
    }
};
//client
class Client
{
    public:

};
int main(int argc,char **argv)
{
    Director *dd = new Director();
    Builder *bb;
    bb = dd->Construct(Director::type1);
    bb->BuildPart();

    delete dd;

    return 0;
}
