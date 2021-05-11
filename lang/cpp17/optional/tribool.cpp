#include <iostream>
#include <optional>

#define F std::cout << __PRETTY_FUNCTION__ << std::endl
namespace nonstd
{
    struct tribool
    {
        private:
        std::optional<bool> _state;
        public:
        tribool &operator=(std::optional<bool> &&rhs)
        {
            F;
            _state.emplace(*rhs);
            return *this;
        }

        tribool &operator=(bool &&rhs)
        {
            F;
            _state.emplace(rhs);
            return *this;
        }

        bool operator==(bool &&rhs)
        {
            F;
            return (rhs == *_state);
        }

        operator bool() const 
        {
            F;
            if (_state)
                return *_state;
            else return false;
        }
    };
}

int main()
{
    nonstd::tribool tristate;
    tristate = true;
    if (tristate)
    {
        std::cout << "it's true\n";
    }
    tristate = std::nullopt;
    if (tristate)
    {
        std::cout << "should not come here\n";
    }
    return 0;
}