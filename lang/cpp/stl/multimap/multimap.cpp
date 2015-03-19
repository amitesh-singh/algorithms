/*
Taken from wiki:
In computer science, a multimap (sometimes also multihash) is a generalization of a map or associative array abstract
data type in which more than one value may be associated with and returned for a given key. Both map and multimap are
particular cases of containers (see for example C++ Standard Template Library containers). Often the multimap is
implemented as a map with lists or sets as the map values.
*/
//multimap implemented after manpreet interview question
#include<iostream>
#include<map>
#include<set>
using namespace std;
namespace yo
{
    template<class T,class V,class U=std::set<V> >
        class multimap
        {
            map<T,U> data_; 
            public:
            typedef typename map<T,U>::iterator iterator;
            U &operator[](T a)
            {
                return data_[a]; 
            }
            void add(T a,V &v)
            {
                data_[a].insert(v);
            }
            iterator begin()
            {
                return data_.begin();
            }
            iterator end()
            {
                return data_.end();
            }

        };
}

int main()
{
    yo::multimap<int,int> mm;
    set<int> s;
    s.insert(1);
    s.insert(2);
    mm[1] = s;

    for(yo::multimap<int,int>::iterator itr = mm.begin();itr!=mm.end();++itr)
    {
        for(set<int>::iterator itr2 = (*itr).second.begin();itr2!=(*itr).second.end();++itr2)
            cout << *itr2 << endl;
    }

    return 0;
}
