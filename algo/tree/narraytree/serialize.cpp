#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <queue>

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
    public:
    node<T> *root = nullptr;
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
        std::cout << p->data << ",";
        for (auto &x: p->children)
            _preorder(x);
    }

    void preorder()
    {
       if (root == nullptr) return;
        _preorder(root);
    }

    void bfs()
    {
        std::queue<node<T> *> q;

        q.push(root);
        int level = 0;
        std::cout << std::endl;
        while (!q.empty())
        {
            int n = q.size();
            level++;
            std::cout << "level: " << level << ": ";
            for (int i = 0; i < n; ++i)
            {
                node<T> *curr = q.front();
                std::cout << curr->data << ", ";
                q.pop();

                for (auto &x: curr->children)
                {
                    q.push(x);
                }
            }
            std::cout << std::endl;
        }
    }


    std::string _serialize(node<T> *p)
    {
        if (p->children.size() == 0) return std::to_string(p->data) + ",#,#,";
        std::string ret = std::to_string(p->data) + ",";
        for (auto &x: p->children)
        {
            ret += _serialize(x);
        }

        return ret;
    }

    void tokenize(const std::string &str,std::string delim, std::queue<std::string> &q)
      {
         int start = 0;
         int end = str.find(delim);

         while (end != std::string::npos)
           {
              q.push(str.substr(start, end - start));

              start = end + delim.size();
              end = str.find(delim, start);
           }

         //since 1,2,#, ignore last space
         //q.push(str.substr(start));
      }

    node<T> *_deserialize(std::queue<std::string> &q)
      {
         if (q.empty()) return nullptr;
         if (q.front() == "#") { q.pop(); return nullptr;}
         node<T> *p = new node<T>(std::stoi(q.front()));
         q.pop();

         while (q.front() != "#")
         {
             node<T> *tmp = _deserialize(q);
             if (tmp)
                p->children.push_back(tmp);
         }

         return p;
      }

    node<T> *deserialize(std::string str)
    {
       std::queue<std::string> q;
       tokenize(str, ",", q);

       return _deserialize(q);
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
    tree.bfs();
    std::string serial_data = tree.serialize();
    std::cout << "serial data: ";
    std::cout << serial_data << std::endl;

    ntree<3, int> tree2;
    tree2.root = tree.deserialize(serial_data);
    tree2.preorder();
    tree2.bfs();
    return 0;
}
