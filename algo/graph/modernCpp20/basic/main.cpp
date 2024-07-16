#include <unordered_map>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_set>

class graph
{
    public:

    void add_vertex(int vertex)
    {
        if (adj_list_.find(vertex) != adj_list_.end()) {
            return;
        }

        adj_list_[vertex] = std::vector<edge>();
    }

    void add_undirected_edge(int v1, int v2)
    {
        add_vertex(v1);
        add_vertex(v2);

        adj_list_[v1].emplace_back(v2, false);
        adj_list_[v2].emplace_back(v1, false);
    }

    void add_directed_edge(int from, int to)
    {
        add_vertex(from);
        add_vertex(to);

        adj_list_[from].emplace_back(to, true);
    }

    void add_directed_edge(auto&&... items)
    {
        (add_directed_edge(items), ...);
    }
    
    void display()
    {
        for (const auto &v: adj_list_) {
            std::cout << v.first << ": ";
            for (const auto &e: v.second) {
                std::cout << (e.is_directed_ ? "-->" : "--") << e.to_<< " ";
            }
            std::cout << '\n';
        }
    }

    enum color { white, grey, black } ;
    bool dfs_iterative_cyclic(int source)
    {
        std::stack<int> s;
        std::unordered_map<int, color> visited;

        s.push(source);
        visited.insert({source, color::grey});
        while (!s.empty()) {
            int vertex = s.top();
            s.pop();
            for (const auto &e: adj_list_[vertex]) {
                auto itr = visited.find(e.to_);
                if (itr == visited.end()) {
                    s.push(e.to_);
                    visited.insert({e.to_, color::grey});
                } else {
                    if (itr->second == color::grey) {
                        std::cout << "cycle is found for " << vertex << "-->" << e.to_ << "\n";
                        return true;
                    }
                }
            }

            std::cout << vertex << " ";
            visited[vertex] = color::black;
        }

        return false;
    }
private:

    struct edge
    {
        int to_;
        bool is_directed_;
        edge(int to, bool directed): to_(to), is_directed_(directed) {}
    };
    std::unordered_map<int, std::vector<edge>> adj_list_;
};


int main()
{
    graph g;

    g.add_directed_edge(1, 2);
    g.add_directed_edge(1, 3);
    g.add_undirected_edge(2, 3);

    g.display();
    std::cout << "is cyclic: " << g.dfs_iterative_cyclic(1) << std::endl;
    
    return 0;
}