#include <string>
#include <iostream>

template<char... C>
struct string_holder
{
    static constexpr std::size_t len = sizeof...(C);
    static constexpr char data[] = {C..., '\0'};
    constexpr operator const char *() const
    {
        return data;
    }
    constexpr operator std::string() const
    {
        return {data, len};
    }
};

int main()
{
    string_holder<'1', '2'> sh;

    std::cout << sh << std::endl;
    
    return 0;
} 