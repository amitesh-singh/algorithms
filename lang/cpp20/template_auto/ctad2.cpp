#include <string>
#include <vector>
#include <concepts>

template <typename T>
struct Storage {
    Storage(T t) : t_(t) {}
    template<typename It> Storage(It begin, It end) : t_(begin,end) {}
    T t_;
};

// Constructor match -> Template instance
Storage(const char*) -> Storage<std::string>;

// Deduction guides can be templated
template<typename It>
Storage(It,It) -> Storage<std::vector<typename It::value_type>>;

int main() {
    Storage a{10};
    // Storage<int> - no guide required, deduced from Storage(T t)

    static_assert(std::same_as<decltype(a), Storage<int>>);

    Storage b{"Hello World!"};
    // Storage<std::string> - follows the const char* guide

    static_assert(std::same_as<decltype(b), Storage<std::string>>);

    std::vector<int> data{1, 2, 3, 4, 5, 6};
    Storage c{data.begin(), data.end()};
    // Storage<std::vector<int>> - follows the double iterator guide

    static_assert(std::same_as<decltype(c), Storage<std::vector<int>>>);
    
    return 0;
}
