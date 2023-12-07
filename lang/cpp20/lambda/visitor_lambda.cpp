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

//write wrapper over std::visit
auto visit_variant(auto&& variant, auto&&... alternatives)
{
    return std::visit(overloaded{std::forward<decltype(alternatives)>(alternatives)...},
           std::forward<decltype(variant)>(variant));
}

int main()
{
    std::vector<Nodes> nodes = {
        NodeA{},
        NodeB{},
    };

    overloaded o{
        [] (const NodeA&) { std::cout << "NodeA" << std::endl; },
        [] (const NodeB&) { std::cout << "NodeB" << std::endl; }
    };

    for (auto&& node : nodes) {
        std::visit(o, node);

        visit_variant(node, 
         [] (const NodeA&) { std::cout << "NodeA" << std::endl; },
        [] (const NodeB&) { std::cout << "NodeB" << std::endl; } );
    }

    // Prints:
    // NodeA
    // NodeB
}