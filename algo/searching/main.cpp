#include<iostream>
#include<vector>
#include "BinarySearchTemplate.h"


using namespace std;


void foo(int i)
{
        cout << i << endl;
};

template<class input,class function>
function my_for_each(input i,input e,function f)
{
        for(;i!=e;++i) f(*i);
}
template<class T>
bool lesser1(T key,vector<int> ,)

int main()
{
        vector<int> vec;
        vec.push_back(10);
        //for_each(vec.begin(),vec.end(),foo);
        //my_for_each(vec.begin(),vec.end(),foo);
        cout << BinarySearch(vec,vec.size(),10,lesser1,greater1);

        return 0;
}
