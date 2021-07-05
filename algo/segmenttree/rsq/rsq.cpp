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

     void update(int array_idx, int val)
     {
        A[array_idx] = val;
        //index of array element in segment tree
        int idx = array_idx + n;
        auto parent = [](int i) { return ((i + 1) >> 1);};
        while (idx != 0)
        {
           idx = parent(idx);
           tree[idx] = tree[left(idx)] + tree[right(idx)];
        }
        
     }
};

int main()
{
   vi v {98, 2, -1, 233};
   segment_tree tree(v);

   tree.print();

   std::cout << tree.rsq(0, 2) << std::endl;
   return 0;
}
