#include "tree.h"
#include <iostream>
#include <ctime>
#include <string>
#include <queue>

//serialize the data in preorder format
// 
//                   1
//            2          3
//         X     X     4    5
//                   X   X  X  X
// output: sting 1, 2, X, X, 3, 4,X,X, 5,X, X
// root, left subtree, right subtree => that's how preorder traversal looks like.

using node = myds::basicnode<int>;

std::string serialize_tree(node *root)
{
    if (root == nullptr) return "X";

    return std::to_string(root->data) + "," + serialize_tree(root->left) + "," + serialize_tree(root->right);
}

void tokenize(const std::string &str, std::string delim, std::queue<std::string> &ans)
{
    size_t start = 0;
    size_t end = 0;
    std::string s = str;
    
    end = s.find(delim);    
    int offset = delim.size();

    while (end != str.npos)
    {
        ans.push(s.substr(start, end - start));
        start = end + offset;

        end = s.find(delim, start);
    }

    ans.push(s.substr(start, end - start));
}

node *_deserialize_tree(std::queue<std::string> &q)
{
    if (q.empty()) return nullptr;
    if (q.front() == "X") { q.pop(); return nullptr;}
    node *root = new node(std::stoi(q.front()));

    q.pop();
    root->left = _deserialize_tree(q);
    root->right = _deserialize_tree(q);

    return root;
}

node *deserialize_tree(const std::string &str)
{
    if (str.size() == 0) return nullptr;
    std::queue<std::string> tokens;
    tokenize(str, ",", tokens);

    return _deserialize_tree(tokens);
}

int main()
{
    std::srand(std::time(nullptr));

    myds::tree<int, node> t;
    for (int i = 0; i < 10; ++i)
        t.insert2(std::rand() % 101);
    t.print();
    std::string str = serialize_tree(t.root);
    std::cout << str << std::endl;
    t.clear();
    t.root = deserialize_tree(str);
    t.print();
    return 0;
}