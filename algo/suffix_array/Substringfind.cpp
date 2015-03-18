#include<iostream>
#include "LCPArray.h"



int main()
{
    vector<char *> vStr;
    vStr.push_back("yoyoyo$");
    SuffixArray<char> sa(vStr);
    sa.Print();

    string substr("yo");
    LCPArray<char> lcp(sa);
    lcp.makeLCP(1);
    lcp.Print();


    return 0;
}
