#include <cstdio>
const static int SIZE = 2 * 1e5;
using ll = long long;

int input[SIZE + 10];
ll hash[SIZE + 10];
int idx = 0;
int hash_idx = 0;
void build()
{
    hash[0] = input[0];
    for (int i = 1; i < idx; ++i)
        hash[i] = hash[i - 1] + input[i];
}

ll getSum(int a, int b)
{
    if (a == b) return input[a];
    if (a == 0) return hash[b];
    return hash[b] - hash[a - 1];
}

int main()
{
    int n, q;
    idx = 0;
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

        printf("%lld\n", getSum(a - 1, b - 1));
    }

    return 0;
}