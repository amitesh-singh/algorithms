#include <unordered_map>
#include <vector>
#include <iostream>

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

    void display()
    {
        for (const auto &v: adj_list_) {
            std::cout << v.first << ": ";
            for (const auto &e: v.second) {
                std::cout << (e.is_directed_ ? "--" : "-->") << e.to_<< " ";
            }
            std::cout << '\n';
        }
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
    g.add_undirected_edge(1, 3);

    g.display();
    
    return 0;
}