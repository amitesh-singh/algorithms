//https://dzone.com/articles/how-to-use-stdvisit-with-multiple-variants
#include <iostream>
#include <variant>

struct Fluid { };
struct LightItem { };
struct HeavyItem { };
struct FragileItem { };

using my_type = std::variant<LightItem, HeavyItem>;
my_type pkgA { LightItem{}};
my_type pkgB { HeavyItem{} };


struct visitor
{
    void operator()(LightItem &l, HeavyItem &h) {
        std::cout << "Light item and heavy item\n";
    }
    void operator()(LightItem &l1, LightItem &l2) {
        std::cout << "light item and light item\n";
    }
    void operator() (HeavyItem &h1, HeavyItem &h2) {
        std::cout << "heavy item and heavy item\n";
    }
    void operator() (HeavyItem &h1, LightItem &h2) {
        std::cout << "heavy item and heavy item\n";
    }
};


template<typename... Ts>
struct overload: Ts...
{
    using Ts::operator()...;
};

template<typename... Ts>
overload(Ts...)->overload<Ts...>;

int main()
{
    
    std::visit(visitor{}, pkgA, pkgB);


    return 0;
}