#include<iostream>
#include "SuffixArray.h"
#include "LCPArray.h"
#include<algorithm>
#include<cstring>
using namespace std;

int main(int argc,char **argv)
{
   //GSA Example ====
   //with 3 strings
   vector<char *> vStr;
   vStr.push_back("ABABC");
   vStr.push_back("BABCA");
   vStr.push_back("ABCBA");
   vStr.push_back("$");
   SuffixArray<char> sa2(vStr);
   sa2.Print();
   LCPArray<char> lcpa2(sa2);
   lcpa2.makeLCP(1);
   lcpa2.Print();
   cout << "LCS:" << lcpa2.LCS() << endl;



   return 0;
}
