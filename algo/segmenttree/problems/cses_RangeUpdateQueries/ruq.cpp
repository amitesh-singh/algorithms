#include <cstdio>
#include <iostream>

using ll = long long;
static const unsigned int SIZE = 2*1e5;
static ll tree[4*SIZE];
int input[SIZE + 10];
int input_idx = 0;

class segment_tree
{
    int *A;
    int n;

    inline int left(int idx) { return (idx << 1);}
    inline int right(int idx) { return (idx << 1) + 1;}
    inline int mid(int L, int R) { return L + (R - L)/2;}

    void build(int idx, int L, int R)
    {
        if (L == R)
        {
            tree[idx] = A[L];
            return;
        }

        build(left(idx), L, mid(L, R));
        build(right(idx), mid(L, R) + 1, R);

        tree[idx] = 0;
    }

    void update(int idx, int L, int R, int a, int b, int u)
      {
         if (a > R or b < L) return;
         if (a <= L and b >= R)
           {
              tree[idx] += u;
              return;
           }
         update(left(idx), L, mid(L, R), a, b, u);
         update(right(idx), mid(L, R) + 1, R, a, b, u);
      }

    ll at(int idx, int L, int R, int k)
    {
        if (L == R)
        {
            return tree[idx];
        }
        if (k >= L and k <= mid(L, R))
            return tree[idx] + at(left(idx), L, mid(L, R), k);
        else
            return tree[idx] + at(right(idx), mid(L, R) + 1, R, k);
    }
    public:
    segment_tree(int *in): A(in), n(input_idx)
    {
        build(1, 0, n - 1);
    }

    void update(int a, int b, int u)
    {
        update(1, 0, n - 1, a, b, u);
    }

    ll at(int k)
    {
        return at(1, 0, n - 1, k);
    }

    void print()
    {
        for (int i = 1; i < 2*n + 2; ++i)
        {
            printf("%d->", tree[i]);
        }
        printf("\n");
    }
};

int main()
{
    int n, q;
    input_idx = 0;
    scanf("%d %d", &n, &q);
    //printf("n: %d, q = %d\n", n , q);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &input[input_idx++]);
    }
    int a, b, q_type, k, u;
    segment_tree stree(input);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &q_type);
        //printf("qtype: %d\n", q_type);
        if (q_type == 2)
        {
           // stree.print();
            scanf("%d", &k);
            printf("%ld\n", stree.at(k - 1));
            //stree.print();
        }
        else
        {
//            stree.print();
            scanf("%d %d %d", &a, &b, &u);
            stree.update(a - 1, b - 1, u);
 //           stree.print();
        }
    }
    return 0;
}
