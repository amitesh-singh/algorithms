#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int T, N;

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
populateStringFromInt(long long a)
{
   //upto 100 digit support
   char buf[100] = {0};
   sprintf(buf, "%lld", a);
   return string(buf);
}

static string
fact(int n)
{
   string ret = "1";
   string s1;

   for (int i = 2; i <= n; ++i)
     {
        s1 = (populateStringFromInt(i));
        ret = multiplyTwoStrings(ret, s1);
     }

   return ret;
}

//note: this will fail for 100!, even long long won't able to handle it.
//Fix me!
#if 0
unsigned long long fact(int n)
{
   unsigned long long sum = 1;
   for (int i = 2; i <= n; ++i)
     {
        sum *= i;
        //cout << "sum: " << sum << endl;
     }

   return sum;
}
#endif

int main()
{
   freopen("input_fact.txt", "r", stdin);

   cin >> T;
   for (int testCase = 1; testCase <= T; ++testCase)
     {
        cin >> N;
        string s = fact(N);
        bool findFirstnonZerofromLeft = false;
        for (int i = 0; i < s.size(); ++i)
          {
             if (s[i] != '0' && !findFirstnonZerofromLeft)
               {
                  findFirstnonZerofromLeft = true;
                  cout << s[i];
               }
             else if (s[i] == '0' && !findFirstnonZerofromLeft)
               continue;
             else
               cout << s[i];
          }
        cout << endl;
        //cout << s << endl;
     }
   return 0;
}
