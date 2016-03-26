#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define INT(a) (a - '0')
static string
addTwoBigNumbers(string &n1, string &n2)
{
   string ret;
   int l1 = n1.size(), l2 = n2.size();
   int *sum = (int *)calloc(l1 > l2 ? l1 : l2, sizeof(int));

   int carry (0);

   int i, j;
   int k = 0;

   i = l1 - 1; j = l2 - 1;

   for (; i >= 0 && j >= 0; i--, j--, k++)
     {
        sum[k] = (INT(n1[i]) + INT(n2[j]) + carry) % 10;
        carry = (INT(n1[i]) + INT(n2[j]) + carry) / 10;
     }

   if (l1 > l2)
     {
        while (i >= 0)
          {
             sum[k++] = (INT(n1[i]) + carry) % 10;
             carry = (INT(n1[i]) + carry) / 10;
             --i;
          }
     }
   else if (l1 < l2)
     {
        while (j >= 0)
          {
             sum[k++] = (INT(n2[j]) + carry) % 10;
             carry = (INT(n2[j]) + carry) / 10;
             --j;
          }
     }
   else
     {
        if (carry > 0)
          {
             sum[k++] = carry;
          }
     }

   for (int x = k - 1; x >= 0; --x)
     {
        ret += (sum[x] + '0');
     }

   free(sum);

   return ret;
}

int main()
{
   int T;
   string n1, n2;
   freopen("input_addition.txt", "r", stdin);

   cin >> T;

   for (int testCase = 1; testCase <= T; ++testCase)
     {
        cin >> n1 >> n2;
        cout << n1 << "+" << n2 << "=";
        cout << addTwoBigNumbers(n1, n2) << endl;
     }

   return 0;
}
