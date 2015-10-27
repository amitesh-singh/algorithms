#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

static string
populateStringFromInt(long long a)
{
   //upto 100 digit support
   char buf[100] = {0};
   sprintf(buf, "%lld", a);
   return string(buf);
}
#include <vector>
static string
multiplyTwoStrings(string s1, string s2)
{
   vector<int> result (s1.size() + s2.size(), 0);

   for (int i = s1.size() - 1; i >= 0; --i)
     {
        for (int j = s2.size() - 1; j >= 0; --j)
          {
             result[i + j + 1] += (s1[i] - '0') * (s2[j] - '0');
          }
     }

   for (int i = s1.size() + s2.size() - 1; i >= 0; --i)
     {
        if (result[i] >= 10)
          {
             result[i - 1] += result[i] / 10;
             result[i] %= 10;
          }
     }
   string ret;

   for (int i = 0; i < result.size(); ++i)
     {
        ret += (result[i] + '0');
     }

   return ret;
}

static string
bigMultiply(long long a, long long b)
{
   string n1, n2;

   n1 = populateStringFromInt(a);
   n2 = populateStringFromInt(b);

   cout << n1 << "*" << n2 << "=";

   return multiplyTwoStrings(n1, n2);
}

int T;
long long n1, n2;
int main()
{
   freopen("input_bigmulti.txt", "r", stdin);

   cin >> T;

   for (int testCase = 1; testCase <= T; ++testCase)
     {
        cin >> n1 >> n2;

        cout << bigMultiply(n1, n2) << endl;
     }
   return 0;
}
