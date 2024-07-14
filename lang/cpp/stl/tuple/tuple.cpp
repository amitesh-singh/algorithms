#include <tuple>
#include <iostream>
#include <optional>

void print(auto x)
{
    std::cout << x << std::endl;
};


template<typename T, size_t... Is>
void print_tuple(const T &c)
{
    (print(std::get<Is>(c)), ...);
}

int main()
{
    std::tuple<int, std::string, int, float> t {1, "ami", 20, 20.2};
    int firstarg = std::get<0>(t);
    std::string &secondarg = std::get<1>(t);

    std::cout << firstarg << std::endl;
    std::cout << secondarg << std::endl;
    //change the value
    std::get<3>(t) = 30.2;

    std::cout << std::get<3>(t) << std::endl;

    //use tie
    int i, j;
    float x;
    std::string name;
    std::tie(i, name, j, x) = t;

    //c++17 way
    //structured binding
    auto [id, fullname, age, marks] = t;

    std::tuple<int, std::string, std::optional<std::string>> person;

    person = std::make_tuple(20, "Ami", std::nullopt);
    auto [id2, firstname, lastname] = person;

    std::cout << "id2: " << id2 << " firstname: " << firstname << (lastname ? *lastname : "") << '\n';

    //iterate std::tuple
    std::cout << "iterate over a tuple: ";
    print_tuple<decltype(t), 0, 1, 2>(t);

    auto [x, y] = []() {
        return std::make_tuple(10, 20);
    }();

    int a, b;

    std::tie(a, b) = []() {
        return std::make_tuple(20, 20);
    }();

    int a1, b1;

    std::tie(a1, b1) = []() {
        return std::make_pair(20, 30);
    }();
    return 0;
}
