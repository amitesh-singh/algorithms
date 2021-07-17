#include <iostream>
#include <vector>
#include <algorithm>

class segment_tree
{
   std::vector<int> tree;
   inline int left(int idx) { return (idx << 1);}
   inline int right(int idx) { return (idx << 1) | 1 ; }
   inline int middle(int L, int R) { return L + (R-L)/2; }

  public:
   segment_tree(int n)
     {
        tree.assign(4*n, 0);
     }

   void insert(int idx, int L, int R, int pos)
     {
        if (pos < L or pos > R) return;
        if ( L == R and pos == L)
          {
             tree[idx]++;
             return;
          }
        int mid = middle(L, R);
        insert(left(idx), L, mid, pos);
        insert(right(idx), mid + 1, R, pos);

        tree[idx] = tree[left(idx)] + tree[right(idx)];
     }

   int query(int idx, int L, int R, int a, int b)
     {
        if (a > R or b < L) return 0;
        if (a <= L and b >= R) return tree[idx];

        int mid = middle(L, R);
        return query(left(idx), L, mid, a, b) + query(right(idx), mid + 1, R, a, b);
     }
};

std::vector<int> countGreater(std::vector<int> &nums)
{
   if (nums.empty()) return {};
   std::vector<int> result;
   int n = nums.size();

   std::vector<std::pair<int, int>> data(n);
   for (int i = 0; i < n; ++i)
     {
        data[i] = std::pair<int, int>(nums[i], i);
     }

   std::sort(data.begin(), data.end(), std::greater<std::pair<int, int>>());
   result.resize(n);

   segment_tree stree(n);
   for (int i =0; i < n; ++i)
     {
        result[data[i].second] = stree.query(1, 0, n - 1, 0, data[i].second);
        stree.insert(1, 0, n -1, data[i].second);
     }

   return std::move(result);
}

int main()
{
   //make IO FAST since std::cin/cout is slower than scanf/printf
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr);

   int T;
   int n;
   std::vector<int> result;
   std::vector<int> input;

   std::cin >> T;
   for (int t = 0; t < T; ++t)
     {
        std::cin >> n;
        input.assign(n + 1, 0);
        result.assign(n, 0);

        int idx = 0;
        for (int i = 0; i < n; ++i)
          {
             std::cin >> input[idx++];
          }

        result = countGreater(input);
        for (int i = 0; i < n; ++i)
        {
           int x = result[i];
           std::cout << x << " ";
        }
        std::cout << '\n';
     }

   return 0;
}
