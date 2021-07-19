#include <iostream>


template<typename T>
struct node
{
    node(std::shared_ptr<const node> const &left, T val, std::shared_ptr<const node> const &right)
    : left(left), val(val), right(right)
    {
    }

    std::shared_ptr<const node> left;
    T val;
    std::shared_ptr<const node> right;
};

template<typename T>
class tree
{
    std::shared_ptr<const node> root;
    public:
    tree() {}
    tree(tree const &left, T val, tree const &right): root(std::make_shared<const node>(left.root, val, right.root))
    {
    }

    bool isempty() const { return !root;}

    Tree insert(T val)
    {
        if (isempty()) return tree(tree(), val, tree());
        if (val < root->val)
            return tree(tr)
    }
   
};
int main()
{
    return 0;
}