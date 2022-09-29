#include <iostream>
#include <compare>
#include <set>

struct person
{
    std::string name;
    auto operator<=>(const person &p) const = default;
};

struct user_defined
{
    std::string name;
    auto operator<=>(const user_defined &ud) const
    {
        if (name < ud.name) return std::strong_ordering::less;
        else if (name == ud.name) return std::strong_ordering::equal;

        return std::strong_ordering::greater;
    }
};

int main()
{
    std::string s1("hello");
    std::string s2("world");
    s1 <=> s2;

    std::set<person> unique_persons;
    unique_persons.emplace(person{"ami"});
    unique_persons.emplace(person{"avi"});

    std::set<user_defined> s;
    s.emplace(user_defined{"ami"});
    s.emplace(user_defined{"avi"});
    
    return 0;
}