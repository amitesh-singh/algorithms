#include<iostream>
#include "SuffixArray.h"
#include "LCPArray.h"
#include<algorithm>
#include<cstring>
using namespace std;

int main(int argc,char **argv)
{
    /*
   if(argc!=2)
   {
       std::cerr << argv[0] << " <string>\n";

       exit(0);
   }

   SuffixArray<char> sa(argv[1]);
   sa.Print();
   for(int i = 1;i<sa.len_;i++)
    {
        cout << "i:" << i << ":";
        cout << LCP(sa[i-1],sa[i]);
        cout << "\n";
    }
    */

   //GSA Example ====
   vector<char *> vStr;
   string s1("apple");
   string s2("maple");
   string s3("$");
   vStr.push_back((char *)s1.c_str());
   vStr.push_back((char *)s2.c_str());
   vStr.push_back((char *)s3.c_str());

   SuffixArray<char> sa1(vStr);
   sa1.Print();
   LCPArray<char> lcpa(sa1);
   lcpa.simpleLCS();
   lcpa.Print();
   cout << "LCS:" << lcpa.LCS() << endl;

   return 0;
}
