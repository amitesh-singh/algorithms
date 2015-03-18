#include "SuffixArray.h"
#include "LCPArray.h"
#include <iostream>
using namespace std;
#define t p->sa_

bool isAllTrue(vector<bool> &vec)
{
    for(int i=0;i<vec.size();++i)
    {
        if(vec[i] == false)
            return false;
    }
    return true;
}
bool isFound(int key,vector<int> &types,vector<bool> &typesChecked)
{
    for(int i=0;i<types.size();++i)
    {
        if(key == types[i])
        {
            typesChecked[i] = true;
            return true;
        }

    }
}
void makeAllFalse(vector<bool> &vec)
{
    for(int i =0;i<vec.size();++i)
    {
        vec[i] = false;
    }
}
//function plugin to LCPArray<T> class
void LCSProblem(void *ptr)
{
    LCPArray<char> *p = (LCPArray<char> *)ptr;
    //cout << p << endl;
    //p->sa_.Print();
    int i=0,j=0;
    int lcp_max = -1;
    int long_index = -1;
    while(i<t.len_ &&  j < t.len_)
    {

        //cout << "initial:i:" << i << " j:" << j << endl;
        isFound(t.data_[j].str_,t.types_,t.typesChecked);
        if(isAllTrue(t.typesChecked))
        {
            int lcp = LCP(t[i],t[j]);
            //cout << "lcp:" << lcp << endl;
            if(lcp_max<=lcp)
            {
                lcp_max =lcp;
                long_index = i;
            }
            //cout << "lcp_max:" << lcp_max << endl;
            i++;
            j = i;
            makeAllFalse(t.typesChecked);
        }
        else
            ++j;    

    }
    //cout << "i:" << i << " j:" << j << endl;
    //cout << "lcp_max:" << lcp_max << endl;
    cout << "LCP string:" << string(t[long_index]).substr(0,lcp_max) << endl;

}
int main(int argc,char **argv)
{

    vector<char *> vStr;
    vStr.push_back("applea$");
    vStr.push_back("mapleb#");
    vStr.push_back("golplec@");
    vStr.push_back("totyertplebcde&");
    vStr.push_back("toplebcde*");
    SuffixArray<char> sa(vStr);
    sa.Print();

    LCPArray<char> lcp(sa);
    lcp.makeLCP(LCSProblem);


    return 0;
}
