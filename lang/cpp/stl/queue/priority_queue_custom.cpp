#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

class person
{
    int _id;
    std::string _name;

    public:

    person(int id, std::string name): _id(id), _name(std::move(name))
    {
    }

    int getId() const
    {
        return _id;
    }

    void print() const
    {
        std::cout << "id: " << _id << " name: " << _name << std::endl;
    }

};

struct personcomp
{
    bool operator()(const person &lhs, const person &rhs)
    {
        return lhs.getId() < rhs.getId();
    }
};

int main()
{
    std::priority_queue<person, std::vector<person>, personcomp> pq;
    pq.push(std::move(person(1, "Ami")));
    pq.push(std::move(person(2, "Poo")));
    pq.push(std::move(person(3, "Avi")));
    pq.push(std::move(person(4, "Aarav")));

    int size = pq.size();
    for (int i = 0; i < size; ++i)
    {
        pq.top().print();
        pq.pop();
    }
    std::cout << std::endl;

    return 0;
}
