#include <iostream>
#include <cstdio>

using namespace std;

int T, N;

//note: this will fail for 100!, even long long won't able to handle it.
//Fix me!
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

int main()
{
   freopen("input_fact.txt", "r", stdin);

   cin >> T;
   for (int testCase = 1; testCase <= T; ++testCase)
     {
        cin >> N;

        cout << fact(N) << endl;
     }
   return 0;
}
