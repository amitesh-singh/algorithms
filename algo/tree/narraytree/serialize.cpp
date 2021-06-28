#include <iostream>
#include <vector>
#include <ctime>
#include <string>

template<typename T>
class node
{
    public:
    T data;
    std::vector<node<T> *> children;

    node (const T &d): data(d), children({}) {}

};

template<int N, typename T>
class ntree
{
    node<T> *root = nullptr;
    public:
    ntree() {}


    void _insert(node<T> *p, const T &d, bool &isdone)
    {
        if (p->children.size() < N)
        {
            p->children.push_back(new node<T>(d));
            isdone = true;
        }
        else
        {
            for (auto &x: p->children)
            {
                if (!isdone)
                    _insert(x, d, isdone);
            }
        }
    }

    void insert(const T &d)
    {
        if (root == nullptr)
        {
            root = new node<T>(d);
            return;
        }
        bool isdone = false;
        _insert(root, d, isdone);
    }

    void _preorder(node<T> *p)
    {
        if (p == nullptr) return;
        std::cout << p->data << ",";
        for (auto &x: p->children)
            _preorder(x);
    }

    void preorder()
    {
        _preorder(root);
    }


    std::string _serialize(node<T> *p)
    {
        if (p->children.size() == 0) return std::to_string(p->data) + ",X,X,";
        std::string ret = std::to_string(p->data) + ",";
        for (auto &x: p->children)
        {
            ret += _serialize(x);
        }

        return ret;
    }

    node<T> *deserialize(std::string str)
    {

    }

    std::string serialize()
    {
        if (root == nullptr) return "";
        return _serialize(root);
    }
};

int main()
{
    std::srand(std::time(nullptr));
    ntree<3, int> tree;

    for (int i = 0; i < 10; ++i)
    {
        tree.insert(i);
    }
    tree.preorder();

    std::string serial_data = tree.serialize();
    std::cout << "serial data: ";
    std::cout << serial_data << std::endl;
    return 0;
}