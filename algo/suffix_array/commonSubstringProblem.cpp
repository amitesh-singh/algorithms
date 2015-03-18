#include<iostream>
using namespace std;

#include "LCPArray.h"


void func(void *ptr)
{
    //cout << ptr << endl;
    LCPArray<char> *p = (LCPArray<char> *)(ptr);
    //p->sa_.Print() ;
    //cout << "hello\n";
      for(size_t i = 0;i<(p->sa_.len_-1);++i)
        {
            p->H_.push_back(LCP(p->sa_[i],p->sa_[i+1]));
        }
}
//plugin function to LCPArra
bool isAllTrue(vector<bool> &vec)
{
    for(int i =0;i<vec.size();++i)
    {
        //cout << "vec:" << i << " :" << vec[i] << endl;
        if(vec[i] == false)
            return false;
    }

    return true;
}
void makeAllFalse(vector<bool> &vec)
{
     for(int i =0;i<vec.size();++i)
    {
        vec[i] = false;
    }


}
bool findVec(vector<int> &types,int key)
{
    for(int i =0;i<types.size();++i)
    {
        if(types[i] == key)
        return true;


    }
    return false;
}
void myFunc(void *ptr)
{
    LCPArray<char> *p = (LCPArray<char> *)(ptr);

    int i =0;
    int j=0;
    int lcp_max = -1;
    int max_i = -1,max_j = -1;
    while(i<(p->sa_.len_)&&j<(p->sa_.len_))
    {
    cout << "initial:\n";
        cout << "i:" << i << " j: " << j << endl;
        makeAllFalse((p->sa_.typesChecked));

        while(1)
        {
        bool flag = isAllTrue(p->sa_.typesChecked);
        cout << "isAllTrue Return: " << flag << endl;
            if(flag)
                break;
            for(int k =0;k<p->sa_.types_.size();++k)
            {
                if(p->sa_.types_[k] == p->sa_.type_[j])
                {
                    p->sa_.typesChecked[k] = true;
                    break;
                }
            }
            ++j;
        }
        cout << "sa_len: " << p->sa_.len_ << endl;
        cout << "i:" << i << " j: " << j << endl;
        if(i >=p->sa_.len_ || j >=p->sa_.len_)
            break;
        int lcp = LCP(p->sa_[i],p->sa_[j]);
        cout << "lcp:"<< lcp <<endl;
        if(lcp_max<=lcp)
        {

            lcp_max = lcp;
            max_i = i;
            max_j = j;
        }
        i = ++j;
    }


    string str(p->sa_[max_i]);
    cout << "LCS:" << str.substr(0,lcp_max) << endl;

}
int main()
{
    vector<char *> vStr;
    vStr.push_back("abababca$");
    vStr.push_back("aababc#");
    vStr.push_back("aaababca@");

    SuffixArray<char> sa(vStr);
    sa.Print();
    LCPArray<char> lcp(sa);
    lcp.makeLCP(myFunc);
    lcp.Print();




    //cout << "LCS:" << lcp.LCS() << endl;







    return 0;
}
