//2 1 2 4 1  (non zero digits)
// find the product of numbers from range 1, 2
// 
#include <cstdio>
using ll = long long;

static const unsigned int SIZE = 1e2;
ll input[SIZE];
int i_idx = 0;
ll dp[SIZE];

void build()
{
    dp[0] = input[0];
    for (int i = 1; i < i_idx; ++i)
        dp[i] = dp[i-1] * input[i];
}

ll getProduct(int a, int b)
{
    if (a == b) return input[b];

    if (a == 0) return dp[b];

    return dp[b]/dp[a-1];
}

ll getLinearProduct(int a, int b)
{
    ll prod = 1;
    for (int i = a; i <= b; ++i)
    {
        prod *= input[i];
    }

    return prod;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; ++i)
        scanf("%ld", &input[i_idx++]);
    
    int a, b;
    build();

    for (int i = 0; i < q; ++i)
    {
        scanf("%d %d", &a, &b);
        ll user_val = getProduct(a - 1, b - 1);
        ll corr_val = getLinearProduct(a - 1, b - 1);
        printf("%lld->", user_val);
        (user_val == corr_val) ? printf("Pass\n") : printf("Fail");
    }
    return 0;
}