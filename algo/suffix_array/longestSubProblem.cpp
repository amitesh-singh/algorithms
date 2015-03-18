#include<iostream>
#include "LCPArray.h"

//Problem:
/*

Given an Integer K, find the length of the longest substring that appears in the text at least K times.

*/

int main()
{

    vector<char *> vStr;
    vStr.push_back("aaaaapale$");
    vStr.push_back("mapaler#");
    SuffixArray<char> gsa(vStr);
    gsa.Print();

    LCPArray<char> lcp(gsa);
    int k =7;
    lcp.makeLCP(k-1);
    lcp.Print();
    cout << "LCS:" << lcp.LCS() << endl;




    return 0;
}
