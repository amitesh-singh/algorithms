#include <iostream>
#include <variant>
#include <vector>

struct NodeA {};
struct NodeB {};

using Nodes = std::variant<NodeA, NodeB>;

template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };

// Some compilers might require this explicit deduction guide
template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

int main()
{
    std::vector<Nodes> nodes = {
        NodeA{},
        NodeB{},
    };

    for (auto&& node : nodes) {
        std::visit(overloaded{
            [] (const NodeA&) { std::cout << "NodeA" << std::endl; },
            [] (const NodeB&) { std::cout << "NodeB" << std::endl; }
        }, node);
    }

    // Prints:
    // NodeA
    // NodeB
}