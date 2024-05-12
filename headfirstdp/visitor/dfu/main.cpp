#include "dfu.hpp"
#include "operation.hpp"

using dfu = std::variant<firmware::dfu::coap, firmware::dfu::coap_confirm>;

#include <vector>
template<typename... Ts>
struct overload: Ts...
{
    using Ts::operator()...;
};

template<typename... Ts>
overload(Ts...)->overload<Ts...>;

int main()
{
    dfu coap = firmware::dfu::coap{ false };
    firmware::dfu::operations::op op_;

    std::visit(op_, coap);

    dfu coap_confirm = firmware::dfu::coap_confirm{};

    std::visit(op_, coap_confirm);

    //std::vector<dfu> dfu_actions { firmware::dfu::coap<true>{}, firmware::dfu::coap_confirm{}};
    dfu act1 { firmware::dfu::coap{true} };
    dfu act2 {firmware::dfu::coap_confirm{}};
    std::visit(op_, act1, act2);

    auto &coap_confirm2 = std::get<1>(act2); 

    std::cout << coap_confirm2.success << std::endl;
    return 0;
}