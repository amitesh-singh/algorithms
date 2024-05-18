#include <iostream>
#include <set>

struct person
{
    int id;
    std::string name;

    //must be const, or else it won't compile
    bool operator<(const person &rhs) const
    {
        return id < rhs.id;
    }
};

int main()
{
    //basic type
    std::set<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(4);

    for (auto &elem: s) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    //extract("key") is added in C++17
    //extract is the only way to take a move-only object out of a set:
    auto extractedElem = s.extract(1); //1 should exists
    //Remember extract just unlink and give ownership to extractedElem. it still exists in memory
    
    std::cout << "extracted value is :" << extractedElem.value() << std::endl;

    extractedElem.value() = 19;

    s.insert(std::move(extractedElem));

    for (auto &elem: s) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    std::set<person> sp;

    sp.insert(person{1, "ami"});
    sp.insert(person{2, "avi"});
    sp.insert(person{5, "aarav"});

    for (auto &elm: sp) {
        std::cout << elm.id << ": " << elm.name << '\n';
    }

    //lets change the value of key 1
    //first we extract "1"

    auto ami = sp.extract(person{1, ""}); //note: name "ami" is not required..
    std::cout << "extracted ami: " << ami.value().id << ": " << ami.value().name << std::endl;

    for (auto &elm: sp) {
        std::cout << elm.id << ": " << elm.name << '\n';
    }


    std::cout << "after insert\n";
    ami.value().name = "amitesh"; ///changed the non-key value
    //insert it

    sp.insert(std::move(ami));
    for (auto &elm: sp) {
        std::cout << elm.id << ": " << elm.name << '\n';
    }

    return 0;
}
