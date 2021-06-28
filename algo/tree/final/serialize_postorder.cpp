#include "tree.h"
#include <iostream>
#include <string>
#include <stack>
#include <ctime>

//serialize the data in postorder format
// 
//                   1
//            2          3
//         X     X     4    5
//                   X   X  X  X
// output: sting 
// left, right, data --> post order.
// X X 2 X X 4 X X 5 3 1
// we will use stack here for holding the data

using node = myds::basicnode<int>;

std::string serialize(node *root)
{
    if (root == nullptr) return "X";

    return serialize(root->left) + "," + serialize(root->right) + "," + std::to_string(root->data);
}

void tokenize(const std::string &str, std::string delim, std::stack<std::string> &q)
{
    int start = 0;
    int end = str.find(delim);

    while (end != std::string::npos)
    {
        q.push(str.substr(start, end - start));
        start = end + delim.size();
        end = str.find(delim, start); 
    }

    q.push(str.substr(start));
}

node *_deserialize(std::stack<std::string> &q)
{
    if (q.empty()) return nullptr;
    if (q.top() == "X") { q.pop(); return nullptr;}
   
    node *root = new node(std::stoi(q.top()));
    q.pop();
    //this is what it is different from preorder.
    root->right = _deserialize(q);
    root->left = _deserialize(q);

    return root;
}

node *deserialize(std::string str)
{
    std::stack<std::string> q;
    tokenize(str, ",", q);
    std::cout << "queue size: " << q.size() << std::endl;
    
    return _deserialize(q);
}

int main()
{
    std::srand(std::time(nullptr));
    myds::tree<int, node> t;
    for (int i = 0; i < 10; ++i)
    {
        t.insert2(rand() % 101);
    }

    t.print();
    std::string serial_data = serialize(t.root);
    std::cout << "post order: serial: " << serial_data << std::endl;
    t.clear();

    t.root = deserialize(serial_data);
    t.print();

    return 0;
}