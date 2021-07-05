#include <cstdio>

#define SIZE 2*100000

int tree[4*SIZE];
int idx = 0;
int input[SIZE];


class segment_tree
{
    int (&A)[SIZE];
    int n;
    int tree_idx = 0;
    int left(int idx)
    {
        return (idx << 1);
    }

    int  right(int idx)
    {
        return (idx << 1)+ 1;
    }

    void build(int idx, int L, int R)
    {
        if (L == R)
        {
            tree[idx] = L;
            return;
        }
        
        int mid = L + (R - L)/2;
        build(left(idx), L, mid);
        build(right(idx), mid + 1, R);
        int p1 = tree[left(idx)], p2 = tree[right(idx)];
        tree[idx] = (A[p1] <= A[p2]) ? p1 : p2; 
    }

    int rmq(int idx, int L, int R, int a, int b)
    {
        if (a > R or b < L) return -1;
        if (a <= L and b >= R) return tree[idx];
        int mid = L + (R - L)/2;
        int p1 = rmq(left(idx), L, mid, a, b);
        int p2 = rmq(right(idx), mid + 1, R, a, b);
        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return A[p1] <= A[p2] ? p1 : p2; 
    }

    public:
    segment_tree(int (&input)[SIZE]): A(input)
    {
        n = idx;
        build(1, 0, n -1);
   }

   int rmq(int a, int b)
   {
       return rmq(1, 0, n -1, a, b);
   }
};

int main()
{
    int n, q;
    idx = 0;

    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i)
    {   
        scanf("%d", &input[idx++]);
    }
    int a, b;
    segment_tree stree(input);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", input[stree.rmq(a - 1, b - 1)]);
    }

    return 0;
}
