//#include <iostream>
#include <cstdio>
using ll = unsigned long long;


const unsigned int SIZE =  2 * 100000 + 2;
ll tree[4*SIZE];

int input_idx = 0;
int input[SIZE];

class segment_tree
{

    int n;
    int *A;
    
    inline int left(int idx) { return (idx << 1);}
    inline int right(int idx) { return (idx << 1)+ 1;}
    inline int mid(int L, int R) { return (L + (R-L)/2);}

    void build(int idx, int L, int R)
    {
        if (L == R)
        {
            tree[idx] = A[L];
            return;
        }

        build(left(idx), L, mid(L, R));
        build(right(idx), mid(L, R) + 1, R);

        tree[idx] = tree[left(idx)] + tree[right(idx)];
    }

    ll rsq(int idx, int L, int R, int a, int b)
    {
        if (a > R or b < L) return 0;
        if (a <= L and b >= R) return tree[idx];
        
        return rsq(left(idx), L, mid(L, R), a, b) +
               rsq(right(idx), mid(L, R) + 1, R, a, b);
    }

    void update(int idx, int L, int R, int array_idx, int val)
      {
         if (L == R and array_idx == L)
           {
              tree[idx] = val;
              return;
           }
         if (array_idx >= L and array_idx <= mid(L, R))
           update(left(idx), L, mid(L, R), array_idx, val);
         else
           update(right(idx), mid(L, R) + 1, R, array_idx, val);

         tree[idx] = tree[left(idx)] + tree[right(idx)];
      }
    public:
    segment_tree(int *in) : A(in), n(input_idx)
    {
        build(1, 0, n - 1);
    }

    ll rsq(int a, int b)
    {
        return rsq(1, 0, n - 1, a, b);
    }

    void update(int array_idx, int val)
    {
       A[array_idx] = val;

       update(1, 0, n - 1, array_idx, val);
    }
};

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &input[input_idx++]);
    }

    int q_type, a, b;
    segment_tree stree(input);
   
    for (int i = 0; i < q; ++i)
    {
        scanf("%d %d %d", &q_type, &a, &b);
        if (q_type == 1)
        {
            stree.update(a - 1, b);
        }
        else
        {
            printf("%lld\n", stree.rsq(a - 1, b -1));
        }
    }


    return 0;
}
