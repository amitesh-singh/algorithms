#include <tuple>
#include <iostream>
#include <optional>

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

    return 0;
}
