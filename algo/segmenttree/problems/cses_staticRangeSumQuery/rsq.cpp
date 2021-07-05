#include <iostream>

const static unsigned int SIZE = 2*100000; 
long long tree[4*SIZE];
int input_idx = 0;
int input[SIZE];

class segment_tree
{
    int n;
    int *A;

    inline int left(int idx) { return (idx << 1) + 1;}

    inline int right(int idx) { return (idx << 1) + 2;}

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

    long long rsq(int idx, int L, int R, int a, int b)
    {
        if (a > R or b < L) return 0;
        if (a <= L and b >= R) return tree[idx];
        int mid = (L) + (R - L)/2;
        
        return rsq(left(idx), L, mid, a, b) + rsq(right(idx), mid + 1, R, a, b);
    }
    public:
    segment_tree(int *input): A(input), n (input_idx)
    {
        build(0, 0, n - 1);
    }

    long long rsq(int a, int b)
    {
        return rsq(0, 0, n - 1, a, b);
    }
};

int main()
{
    int n, q;
    std::cin.sync_with_stdio(false);

    std::cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> input[input_idx++];
    }
    segment_tree segtree(input);
    int a, b;
    for (int i = 0; i < q; ++i)
    {
        std::cin >> a >> b;
        std::cout << segtree.rsq(a -1, b - 1) << '\n';
    }
    return 0;
}