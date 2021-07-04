#include <iostream>
#include <vector>


using vi = std::vector<int>;
class segment_tree
{
    vi tree;
    vi &A;
    int n;

    int left(int idx)
    {
        return (idx << 1) + 1;
    }

    int  right(int idx)
    {
        return (idx << 1) + 2 ;
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
    segment_tree(vi &input): A(input), n (input.size())
    {
        tree.reserve(4*n);
        tree.assign(4*n, 0);
        build(0, 0, n -1);
   }

   int rmq(int a, int b)
   {
       return rmq(0, 0, n -1, a, b);
   }
};

int main()
{
   //this makes std::cin/cout faster
    std::cin.sync_with_stdio(false);
    int n, q;
    vi input;
    int val;

    std::cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {   
        std::cin >> val;
        input.push_back(val);
    }
    int a, b;
    segment_tree stree(input);
    for (int i = 0; i < q; ++i)
    {
        std::cin >> a >> b;
        std::cout << input[stree.rmq(a - 1, b - 1)] << '\n';
    }

    return 0;
}
