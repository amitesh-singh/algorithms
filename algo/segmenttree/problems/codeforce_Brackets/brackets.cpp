#include <iostream>
#include <vector>

struct node
{
    int ans {0}; //correct sequence
    int c {0}; //closed
    int o{0}; //open
    node() = default;
};

class segment_tree
{
    std::string &seq;
    int n;
    std::vector<node> tree;
    int left(int idx) { return (idx << 1);}
    int right(int idx) { return (idx << 1 )| 1;}
    int middle(int L, int R) { return L + ((R-L)>> 1);}

    node combine(node a, node b)
    {
        node ret;

        int tmp = std::min(a.o, b.c);
        ret.ans = a.ans + b.ans + tmp;

        ret.o = a.o + b.o - tmp;
        ret.c = a.c + b.c - tmp;

        return ret;
    }

    void build(int idx, int L, int R)
    {
        if (L == R)
        {
            if (seq[L] == '(')
            {
                tree[idx].ans = 0;
                tree[idx].c = 0;
                tree[idx].o = 1;
            }
            else
            {
                tree[idx].ans = 0;
                tree[idx].c = 1;
                tree[idx].o = 0;
            }

            return;
        }

        int mid = middle(L, R);

        build(left(idx), L, mid);
        build(right(idx), mid + 1, R);

        tree[idx] = combine(tree[left(idx)], tree[right(idx)]); 
    }
    node query(int idx, int L, int R, int a, int b)
    {
        if (a > R or b < L) return node();
        if (a <= L and b >=R) return tree[idx];
        int mid = middle(L, R);

        return combine(query(left(idx), L, mid, a ,b), query(right(idx), mid + 1, R, a, b));
    }
    public:
        segment_tree(std::string &s): seq(s), n (seq.size())
        {
            tree.assign(4*n, node());
            build(1, 0, n - 1);
        }

        node query(int a, int b)
        {
            return query(1, 0, n - 1, a, b);
        }
};
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string seq;
    std::cin >> seq;
    segment_tree stree(seq);
    int q;
    std::cin >> q;
    int a, b;

    //stree.print();
    for(int i = 0; i < q; ++i)
    {
        std::cin >> a >> b;
        std::cout << (stree.query(a-1, b-1)).ans*2 << '\n';
    }
    return 0;
}