#include <iostream>
#include <vector>
#include <queue>

struct node
{
    int data;
    std::vector<node *> children;
    node *parent = nullptr;
    node(int d) : data(d)
    {
    }
};

template<int N>
class n_tree
{
    node *root = nullptr;

    void _insert(node *p, int d, bool &isAdded)
    {
        if (p->children.size() < N)
        {
           if (!isAdded)
           {
               isAdded = true;
               p->children.push_back(new node(d));
           }
           return;
        }
        else
        {
            for (auto x: p->children)
                _insert(x, d, isAdded);
        }
    }

    void _preorder(node *p)
    {
        if (p == nullptr) return;
        std::cout << p->data << std::endl;
        for (auto x: p->children)
            _preorder(x); 
    }

    void _bfs(node *p)
    {
        if (p == nullptr)
            return;
        int level = 0;
        std::queue<node *> q;
        q.push(p);

        while (!q.empty())
        {
            int n = q.size();
            
            for (int i = 0; i < n; ++i)
            {
                node *curr = q.front();
                q.pop();
                for(auto x: curr->children)
                    q.push(x);

                std::cout << curr->data << ", ";
            }
            level++;
            std::cout << "     level: " << level;
            std::cout << std::endl;
        }
        
    }
    public:
    void insert(int d)
    {
        if (root == nullptr)
        {
            root = new node(d);
            return;
        }
        bool isAdded = false;
        _insert(root, d, isAdded);
    }

    void bfs()
    {
        _bfs(root);
    }
    void preorder()
    {
        _preorder(root);
    }

    int _maxDepth_DFS(node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int maxDepth = 0;
        for (auto x: root->children)
        {
            // or maxDepth = std::max(maxDepth, _maxDepth_DFS);
            int h = _maxDepth_DFS(x);
            if (h > maxDepth)
                maxDepth = h;
        }

        return maxDepth + 1;
    }

    //it is the height of the tree.
    int maxDepth_DFS()
    {
        return _maxDepth_DFS(root);
    }

    int maxDepth_BFS()
    {
        int level = 0;
        
    }
};

int main()
{
    n_tree<3> t;
    for (int i = 0; i < 15; ++i)
        t.insert(i);
    t.preorder();
    std::cout << "BFS: \n";
    t.bfs();
    std::cout << "max depth: " << t.maxDepth_DFS() << std::endl;
    return 0;
}