//Range max query 

#include <iostream>
#include <vector>

using vi = std::vector<int>;
class segment_tree
{
    vi tree;
    vi &A;
    int n;
    int left(int idx) { return (idx << 1);}
    int right(int idx) {return (idx << 1) + 1;}
    int mid(int L, int R) {return L + (R - L)/2;}

    void build(int idx, int L, int R)
    {
        if (L == R)
        {
            tree[idx] = L;
            return;
        }

        build(left(idx), L, mid(L, R));
        build(right(idx), mid(L, R)+ 1, R);
        int p1 = tree[left(idx)];
        int p2 = tree[right(idx)];
        tree[idx] = A[p1] >= A[p2] ? p1 : p2;
    }

    int rmq(int idx, int L, int R, int a,  int b)
    {
        if (a > b) return -1;
        if (a == L and b == R) return tree[idx];
        //this minimizes other calls. 

        int p1 = rmq(left(idx), L, mid(L, R), a, std::min(b, mid(L, R)));
        int p2 = rmq(right(idx),mid(L, R) + 1, R, std::max(a, mid(L, R) + 1), b);
        if (p1 == -1) return p2;
        if (p2 == -1) return p1;

        return A[p1] >= A[p2] ? p1 : p2;
    }

    void update(int idx, int L, int R, int arr_idx, int val)
    {
        if (L == R and arr_idx == L)
        {
            A[tree[idx]] = val;
            return;
        }
        if (arr_idx >= L and arr_idx <= mid(L, R))
            update(left(idx), L, mid(L, R), arr_idx, val);
        else if (arr_idx >= mid(L, R) + 1 and arr_idx <= R)
            update(right(idx), mid(L, R) + 1, R, arr_idx, val);
        int p1 = tree[left(idx)];
        int p2 = tree[right(idx)];
        tree[idx] = A[p1] >= A[p2] ? p1 : p2;
    }
    public:
    segment_tree(vi &input): A(input), n (input.size())
    {
        tree.assign(4*n, 0);
        
        build(1, 0, n - 1);
    }

    int rmq(int a, int b)
    {
        return rmq(1, 0, n - 1, a, b);
    }
    void print()
    {
        for (auto &x: tree)
            std::cout << x << "->";
        std::cout << std::endl;
    }

    void update(int arr_idx, int val)
    {
        update(1, 0, n - 1, arr_idx, val);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    vi input;

    int val;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> val;
        input.push_back(val);
    }

    int q_type, a, b;

    segment_tree stree(input);
    stree.print();
    for (int i = 0; i < q; ++i)
    {
        std::cin >> q_type;
        if (q_type == 2)
        {
            std::cin >> a >> b;
            std::cout << input[stree.rmq(a, b)] << "\n";
        }
        else
        {
            std::cin >> a >> b;
            stree.update(a, b);
        }
    }
}