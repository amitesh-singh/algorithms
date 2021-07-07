/*
we want to find the number of zeros in a given range, 
and additionally find the index of the k-th zero using a
 second function.
**/

#include <iostream>
#define makefastio std::ios_base::sync_with_stdio(false); \
                   std::cin.tie(nullptr)
#include <vector>
using vi = std::vector<int>;
class segment_tree
{
    vi tree;
    vi &A;
    int n;
    
    inline int left (int idx) { return (idx << 1);}
    inline int right(int idx) { return (idx << 1) + 1;}
    inline int middle(int L, int R) { return L + (R - L)/2;}

    void build(int idx, int L, int R)
    {
        if (L == R)
        {
            tree[idx] = A[L] == 0 ? 1 : 0;
            return;
        }

        int mid = middle(L, R);
        build(left(idx), L, mid);
        build(right(idx), mid + 1, R);

        tree[idx] = tree[left(idx)] + tree[right(idx)];
    }

    int count_zeroes(int idx, int L, int R, int a, int b)
    {
        if (a > R or b < L) return 0;
        if (a <= L and b >= R) return tree[idx];
        
        return count_zeroes(left(idx), L, middle(L, R), a, b) +
                count_zeroes(right(idx), middle(L, R) + 1, R, a, b);
    }

    int find_kthZero(int idx, int L, int R, int k)
    {
        if (k > tree[idx]) return -1;
        if (L == R) return L;
        int mid = middle(L, R);

        if (k <= tree[left(idx)])
            return find_kthZero(left(idx), L, mid, k);
        else
            return find_kthZero(right(idx), mid + 1, R, k - tree[left(idx)]);
    }
    public:

    segment_tree(vi &in): A(in), n(in.size())
    {
        tree.assign(4*n, 0);
        build(1, 0, n - 1);
    }

    int count_zeroes(int a, int b)
    {
        return count_zeroes(1, 0, n -1, a, b);
    }

    int find_kthZero(int k)
    {
        return find_kthZero(1, 0, n -1, k);
    }
};

int main()
{
    makefastio;
    int n, q;
    std::cin >> n >> q;
    vi input;
    input.reserve(n);
    int val;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> val;
        input.push_back(val);
    }

    int a, b;
    int q_type;
    segment_tree stree(input);
    int k;
    for (int i = 0; i < q; ++i)
    {
        std::cin >> q_type;
        if (q_type == 2)
        {
            std::cin >> a >> b;
            std::cout << stree.count_zeroes(a, b) << "\n";
        }
        else
        {
            std::cin >> k;
            int pos = stree.find_kthZero(k); 
            std::cout << pos << std::endl;
        }
    }

    return 0;
}