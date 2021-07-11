#include <iostream>
//find the ocurrence of an element 'x' in a given range (a,b) in an array
#include <set>
#include <vector>

const unsigned int SIZE = 2000;
int input[SIZE];
int input_idx = 0;

class segment_tree
{
   std::vector<std::multiset<int>> tree;
   int *A;
   int n;

   int left(int idx)
     {
        return (idx << 1);
     }
   int right(int idx)
     {
        return (idx << 1) + 1;
     }

   int middle(int L, int R) { return L + (R - L)/2;}

   void build(int idx, int L, int R)
     {
        if (L == R)
          {
             std::multiset<int> m;
             m.insert(A[L]);
             tree[idx] = m;
             return;
          }
        int mid = middle(L, R);

        build(left(idx), L, mid);
        build(right(idx), mid + 1, R);

        //merge two sets into one.
        tree[idx].insert(tree[left(idx)].begin(), tree[left(idx)].end());
        tree[idx].insert(tree[right(idx)].begin(), tree[right(idx)].end());
     }

   int foq(int idx, int L, int R, int a, int b, int x)
     {
        if (a > R or b < L) return 0;
        if (a <= L and b >= R)
          {
             return tree[idx].count(x);
          }

        int mid = middle(L, R);
        return foq(left(idx), L, mid, a, b, x) + foq(right(idx), mid + 1, R, a, b, x);
     }

  public:
   segment_tree(int *in): A(in)
   {
      n = input_idx;
      std::multiset<int> m;
      tree.assign(4*n, m);
      build(1, 0, n - 1);
   }

   int foq(int a, int b, int x)
     {
        return foq(1, 0, n - 1, a, b, x);
     }
};

int main()
{
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr);

   int n, q;
   std::cin >> n >> q;

   for (int a = 0; a < n; ++a)
     {
        std::cin >> input[input_idx++];
     }

   segment_tree stree(input);
   int x, a, b;
   for (int i = 0; i < q; ++i)
     {
        std::cin >>  a >> b >> x;
        std::cout << stree.foq(a, b, x) << std::endl;
     }

   return 0;
}
