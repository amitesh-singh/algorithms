
#include <variant>

//using dfu = std::variant<firmware::dfu::coap>;


namespace firmware::dfu::operations
{
    struct op
    {
        void operator()(auto, auto)
        {

        }
        void operator()(auto) {}
        void operator() (firmware::dfu::coap_confirm &c)
        {
            c.confirm();
        }
        void operator()(firmware::dfu::coap &c)
        {
            c.flash();
        }
        void operator()(firmware::dfu::coap &c, firmware::dfu::coap_confirm &confirm)
        {
            c.flash();
            confirm.confirm();
        }
    };
}