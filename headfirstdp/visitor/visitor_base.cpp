#include <iostream>
#include <variant>
#include <vector>

/*
 * The order of overloads doesn’t matter here. Specialization is preferred over the base class.
 */

struct NodeBase {};
struct NodeA : public NodeBase{};
struct NodeB : public NodeBase{};

using Nodes = std::variant<NodeA, NodeB>;

struct Visitor {
    void operator() (const NodeA&) { std::cout << "NodeA" << std::endl; }
    void operator() (const NodeBase&) { std::cout << "NodeBase" << std::endl; }
};

int main()
{
    std::vector<Nodes> nodes = {
        NodeA{},
        NodeB{},
    };

    for (auto&& node : nodes) std::visit(Visitor{}, node);

    // Prints:
    // NodeA
    // NodeBase
}
