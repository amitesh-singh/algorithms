#include <cstdio>

static const unsigned int SIZE = 2*1e5;


unsigned int dp[SIZE + 10];
unsigned int input[SIZE + 10];
int idx = 0;

inline void build()
{
   dp[0] = input[0];
   for (int i = 1; i < idx; ++i)
     dp[i] = dp[i - 1] ^ input[i];
}

inline unsigned int getXORSum(int a, int b)
{
   if (a == b) return input[a];
   if (a == 0) return dp[b];
   //inverse of xor is XOR --> remmeber this
   return dp[b] ^ dp[a - 1];
}

int main()
{
   int n, q;
   scanf("%d %d", &n, &q);

   for (int i = 0; i < n; ++i)
     {
        scanf("%d", &input[idx++]);
     }

   build();

   int a, b;

   for (int i = 0; i < q; ++i)
     {
        scanf("%d %d", &a, &b);
        printf("%d\n", getXORSum(a - 1, b - 1));
     }

   return 0;
}
