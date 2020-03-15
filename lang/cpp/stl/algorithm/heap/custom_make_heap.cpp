#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct person
{
    int id;
    std::string name;
    person(int id1, std::string name1): id(id1), name(std::move(name1))
    {
    }

    bool operator <(const person &rhs)
    {
        return id < rhs.id;
    } 
};

int main()
{
    std::vector<person> v {
        person(1, "ami"),
        person(2, "a1"),
        person(3, "cutiepi")
    };

    std::cout << "max heap: \n";
    std::make_heap(begin(v), end(v));

    for (auto &x: v)
    {
        std::cout << "id: " << x.id << " name: " << x.name << std::endl;
    }

    std::cout << "popping up: \n";
    std::pop_heap(v.begin(), v.end());
    v.pop_back();
    
    for (auto &x: v)
    {
        std::cout << "id: " << x.id << " name: " << x.name << std::endl;
    }

    std::cout << "min heap with custom comparator: \n";
    std::make_heap(begin(v), end(v), [](const person &lhs, const person &rhs)->bool
    {
        return lhs.id > rhs.id;
    });

    for (auto &x: v)
    {
        std::cout << "id: " << x.id << " name: " << x.name << std::endl;
    }

    std::cout << "pushed a 'nobody' person\n";
    v.push_back(person(-1, "nobody"));
    std::push_heap(begin(v), end(v), [](const person &lhs, const person &rhs)->bool
    {
        return lhs.id > rhs.id;
    });
    
    for (auto &x: v)
    {
        std::cout << "id: " << x.id << " name: " << x.name << std::endl;
    }
    
    std::cout << "popping heap\n";

    std::pop_heap(v.begin(), v.end(), [](const person &lhs, const person &rhs)->bool
    {
        return lhs.id > rhs.id;
    });
    v.pop_back();

    for (auto &x: v)
    {
        std::cout << "id: " << x.id << " name: " << x.name << std::endl;
    }
    return 0;
}
