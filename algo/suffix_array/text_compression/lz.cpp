#include<iostream>
#include<cstdio>
#include"../LCPArray.h"
// codeblock does not support sstream :/

//#include <sstream>

string itos(int a)
{
    char buff[10];
    memset(buff,0,10);
    sprintf(buff,"%d",a);
    string str(buff);
    return str;
}
using namespace std;

//function based on Ziv-Lempen data compression algo
void lz_encode(string &T,string &C)
{
    C+=T[0];

    for(size_t i = 1;i<T.length();++i)
    {
        int lcp_max = 0;
        int longest_j = -1;
        string prior_i = T.substr(0,i);
        cout << "prior_i:" <<prior_i << endl;
        string next_i = T.substr(i,T.length());
        cout << "next_i:" << next_i << endl;
        vector<char *> vStr;
        vStr.push_back((char *)prior_i.c_str());
        SuffixArray<char> sa(vStr);
        for(size_t j=0;j<sa.len_;++j)
        {

            int lcp = LCP(sa[j],(char *)next_i.c_str());
            if(lcp_max<lcp)
            {
                lcp_max = lcp;
                longest_j = j;
            }
        }
        if(longest_j != -1 && lcp_max != 0)
        {


        cout << "lcp_max:" << lcp_max << endl;
        cout << "longest_j:" << longest_j << endl;
        //si and li values
        string s_i  = string(sa[longest_j]);
        string prior (s_i.substr(0,lcp_max));
        cout << "prior:" << prior << endl;
        int li = prior.length();
        int si = longest_j;
        //sstream ss;
        //ss << si;
         C+="(";
         C+=itos(si);
         C+=",";
         C+=itos(li);
         //C+= ss.str();
         //ss.clear();
         //ss << li;
         //C+=ss.str();
         C+=")";
         i+=li-1;
        }
        else
        {
            C+=T[i];
            cout << "C:" << C << endl;

        }
    }


    return;
}

int main(int argc,char **argv)
{
    string T("ababcaabaavbbab");

    string out;
    lz_encode(T,out);
    cout << "compressed Text:" << out << endl;



    return 0;
}
