#include<iostream>
#include<vector>
#include<algorithm>
#define F cout << __PRETTY_FUNCTION__ << endl

using namespace std;

class Observer;

class Subject
{
    public:
    vector<Observer *> coll_;
    void attach(Observer *);
    void detach(Observer *);
    void NotifyAll();
};

class Observer
{
    public:
    virtual void notify() = 0;
};

void Subject::attach(Observer *o)
{
    coll_.push_back(o);
}
void Subject::detach(Observer *o)
{
    coll_.erase(std::remove(coll_.begin(),coll_.end(),o),coll_.end());
}
void Subject::NotifyAll()
{
    for(int i=0;i<coll_.size();++i)
    {
        coll_[i]->notify();
    }
}
class ObserverA:public Observer
{
    public:
    void notify()
    {
        F;
    }

};


class ObserverB:public Observer
{
    public:
    void notify()
    {
        F;
    }
};

int main()
{
    ObserverB ob;
    ObserverA oa;

    Subject sub;
    sub.attach(&ob);
    sub.attach(&oa);
    //Notify All
    sub.NotifyAll();

    //detach ObserverA
    sub.detach(&oa);
    //Notify All
    sub.NotifyAll();


    return 0;
}
