#include <set>
#include <iostream>

//we just need to define < const operator 
struct person
{
    int id;
    std::string name;

    //note: < must be const or else it won't compile!!
    bool operator<(const person &rhs) const
    {
        return id < rhs.id;
    }
};


int main()
{
    std::multiset<person> sp;

    auto print = [](auto &s) {
        for (const auto &elm: s) {
            std::cout << elm.id << ": " << elm.name << '\n';
        }
    };

    sp.insert(person{1, "ami"});
    sp.insert(person{1, "pooja"});
    sp.insert(person{2, "avi"});
    sp.insert(person{4, "xyz"});

    print(sp);


    //change "ami" with key 1 to "amitesh"
    //{} is list initializer, which eventually calls ctor (int, const std::string&)
    auto extractElem = sp.extract(person{10, ""}); //note: we only care about id, not the other key
    if (extractElem.empty()) {
        std::cout << "this is not present here\n";
        // the below line would compile but it would crash, since there is no memory allocated    
        //extractElem.value().id = 10;
    }

    //
    extractElem = sp.extract(person{1, ""});

    extractElem.value().name = "amitesh";

    sp.insert(std::move(extractElem));

    print(sp);

    std::cout << "entries with key 1: " << sp.count(person{1, ""}) << '\n';

    //lets find the nodes using equal range api
    auto range = sp.equal_range(person{1, ""});

    if (range.first == range.second) {
        std::cout << "only single element";
    } else {
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << it->id << ": " << it->name << ';';
        }
    }
    return 0;
}