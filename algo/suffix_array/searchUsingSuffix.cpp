#include<iostream>
#include "SuffixArray.h"
#include "LCPArray.h"
#include<algorithm>
#include<cstring>
using namespace std;

int main(int argc,char **argv)
{

   //GSA Example ====
   vector<char *> vStr;
   string s1("apple$");
   vStr.push_back((char *)s1.c_str());

   SuffixArray<char> sa1(vStr);
   sa1.Print();
   cout << sa1.binarySearch("ple") << endl;

   return 0;
}
