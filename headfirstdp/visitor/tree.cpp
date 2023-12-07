#include <iostream>
#include <variant>

struct leaf {};
using tree = std::variant<leaf, class node *>;
class node
{
public:
    tree left, right;
};

struct countleaves
{
    countleaves() = default;
    int operator()(leaf &l)
    {
        return 1;
    }

    int operator()(node *n)
    {
        int leftCount = std::visit(*this, n->left);  
        int rightCount = std::visit(*this, n->right);
        return leftCount + rightCount;
    }
};

int main()
{
    node root;   
    root.left = new node{leaf{}, leaf{}};
    root.right = new node{leaf{}, leaf{}};
    tree t {&root};

    int result = std::visit(countleaves{}, t);
    std::cout << "Number of leaves: " << result << std::endl;
    return 0;
}
