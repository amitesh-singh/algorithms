//RSQ -> range sum query
// return sum of elements from i, j in an array 

#include <iostream>
#include <vector>

using vi = std::vector<int>;
using lvi = std::vector<long>;
class segment_tree
{
   lvi tree;
   vi &A;
   int n;

   inline int left(int idx)
     {
        return (idx << 1) + 1;
     }

   inline int right(int idx)
     {
        return (idx << 1) + 2;
     }

   inline int mid(int L, int R)
     {
        return L + (R - L)/2;
     }

   void build(int idx, int L, int R)
     {
        if (L == R)
          {
             tree[idx] = A[L];
             return;
          }

        int mid = L + (R - L)/2;
        build(left(idx), L, mid);
        build(right(idx), mid + 1, R);

        tree[idx] = tree[left(idx)] + tree[right(idx)];
     }

   long rsq(int idx, int L, int R, int a, int b)
     {
        if (a > R or b < L) return 0;
        if (a <= L and b >= R) return tree[idx];

        int mid = L + (R - L)/2;
        return rsq(left(idx), L, mid, a, b) + rsq(right(idx), mid + 1, R, a, b);
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
   segment_tree(vi &input): A(input), n (input.size())
   {
      tree.reserve(4 * n);
      tree.assign(4 *n, 0);

      build(0, 0, n - 1);
   }

   long rsq(int a, int b)
     {
        return rsq(0, 0, n - 1, a, b);
     }

   void print()
     {
        for (auto &x: tree)
          std::cout << x << ",";
        std::cout << std::endl;
     }

   //don't mix Top to bottom and bottom to top approaches
     void update(int array_idx, int val)
     {
        A[array_idx] = val;
        update(0, 0, n - 1, array_idx, val);
     }
};

int main()
{
   vi v {98, 2, -1, 233};
   segment_tree tree(v);

   tree.print();

   std::cout << tree.rsq(0, 2) << std::endl;
   std::cout << tree.rsq(0, 3) << std::endl;

   tree.update(0, -1);
   std::cout << tree.rsq(0, 2) << std::endl;
   std::cout << tree.rsq(0, 3) << std::endl;
   return 0;
}
