#include <iostream>
#include <optional>
#include <string>
#include <cassert>

struct person
{
    std::string first_name;
    std::optional<std::string> middle_name;
    std::string last_name;

    void print()
    {
        std::cout << first_name << " ";
        if(middle_name) std::cout << *middle_name << " ";
        std::cout << last_name << std::endl;
    }
};

int main()
{
    person p1 {"Amitesh", std::nullopt, "Singh"};
    person p2 {"Amit", "Kumar", "Singh"};
    p1.print();
    p2.print();

    assert(!p1.middle_name);

    person p3;
    p3.first_name = "meh";
    p3.middle_name.emplace("lol");
    p3.last_name = "lol2";

    p3.print();

    std::optional<int> i { 10};
    std::cout << "i = " << *i << std::endl;
    i.emplace(11);
    std::cout << "i = " << *i << std::endl;

    return 0;
}