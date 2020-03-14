#include <iostream>
#include <map>
#include <list>

using namespace std;

struct Ptr
{
    int val;
};

void
addMapValue(map<Ptr *, list<Ptr *> > &mList,
            Ptr *p1, Ptr *p2)
{
    map<Ptr *, list<Ptr *> >::iterator itr1 = mList.find(p1);
    if (itr1 != mList.end())
    {
        mList[p1].push_back(p2);
    }
    else
    {
        list<Ptr *> l;
        l.push_back(p2);
        mList[p1] = l;
    }
}

int main()
{
    map<Ptr *,  Ptr *> m;

    Ptr *p1 = new Ptr();
    Ptr *p2 = new Ptr();

    p1->val = 1;
    p2->val = 2;
    m[p1] = p1;
    m[p2] = p2;

    map<Ptr *, Ptr *>::iterator itr = m.begin();

    for (; itr != m.end(); ++itr)
    {
        cout << itr->first << " : " << itr->second << endl;
    }

    map<Ptr *, list<Ptr *> > mList;

    addMapValue(mList, p1, p2);
    addMapValue(mList, p1, p1);
    addMapValue(mList, p2, p1);

    map<Ptr *, list<Ptr *> >::iterator itr1 = mList.begin();
    for (; itr1 != mList.end(); ++itr1)
    {
        cout << itr1->first << " : " << endl; //<< itr1->second << endl;
        list<Ptr *>::iterator lItr = itr1->second.begin();
        for (; lItr != itr1->second.end(); ++lItr)
        {
            cout << (*lItr)->val << ",";
        }
        cout << endl;
    }

    delete p1; delete p2;

    return 0;
}
