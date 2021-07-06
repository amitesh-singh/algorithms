#include <cstdio>

const static unsigned int SIZE = 2 * 1e5;
int input[SIZE + 10];
int tree[4*SIZE];
int input_idx = 0;

class segment_tree
{
   int *A;
   int n;

   inline int left(int idx) { return 2*idx;}
   inline  int right(int idx) { return 2*idx + 1; }
   inline  int parent(int idx) { return (idx >> 1); }
   inline int mid(int L, int R) { return (L + (R - L)/2); }

   //top to bottom
   void build(int idx, int L, int R)
     {
        if (L == R)
          {
             tree[idx] = L;
             return;
          }

        build(left(idx), L, mid(L, R));
        build(right(idx), mid(L, R) + 1, R);

        int p1 = tree[left(idx)], p2 = tree[right(idx)];
        tree[idx] = (A[p1] <= A[p2]) ? p1 : p2;
     }

   int rmq(int idx, int L, int R, int a, int b)
     {
        if (a > R or b < L) return -1;
        if (a <=L and b >= R) return tree[idx];

        int p1 = rmq(left(idx), L, mid(L, R), a, b);
        int p2 = rmq(right(idx), mid(L, R) + 1, R, a, b);
        if (p1 == -1) return p2;
        if (p2 == -1) return p1;

        return A[p1] <= A[p2] ? p1: p2;
     }

   void update(int idx, int L, int R, int array_index, int val)
     {
        if (L == R and array_index == L)
          {
             tree[idx] = L;
             return;
          }
        if (array_index >= L and array_index <= mid(L, R))
          update(left(idx), L, mid(L, R), array_index, val);
        else
          update(right(idx), mid(L, R) + 1, R, array_index, val);

        tree[idx] = A[tree[left(idx)]] <= A[tree[right(idx)]] ? tree[left(idx)] : tree[right(idx)];
     }

  public:
   segment_tree(int *in): A(in), n(input_idx)
   {
      build(1, 0, n - 1);
   }

   int rmq(int a, int b)
     {
        return rmq(1, 0, n - 1, a, b);
     }

   void update(int k, int u)
     {
        A[k] = u;

        update(1, 0, n - 1, k, u);

     }
   void print()
     {
        for (int i = 1; i < 2*n; ++i)
          printf("%d->", tree[i]);
        printf("\n");
        printf("arr:\n");
        for (int i = 0; i < n; ++i)
          printf("%d,", A[i]);
        printf("\n");
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
             printf("%d\n", input[stree.rmq(a - 1, b - 1)]);
          }
     }

   return 0;
}
