#include <unordered_set>
#include <iostream>


class A
{
    public:
    int a;

    // following operator is needed for unordered_set
    // make sure it's a const function  
    bool operator==(const A& rhs) const
    {
        return a == rhs.a;
    }
};

struct A_Hash
{
    //functor 
    size_t operator()(const A& rhs) const
    {
        return std::hash<int>{}(rhs.a);
    }
};

int main()
{
    auto print_set = [](auto &s) {
        for (const auto& x: s) {
            std::cout << x.a << " ";
        }
        std::cout << '\n';
    };
    std::unordered_set<A, A_Hash> us;

    us.insert(A(1));
    us.emplace(A(2));
    us.emplace_hint(us.begin(), A(4));

    print_set(us);

    //we can also use lambda function, which is a bit trickier
    auto lambda_hash = [](const auto &obj) {
        return std::hash<int>{}(obj.a);
    };

    std::unordered_set<A, decltype(lambda_hash)> us2;
    us2.emplace(A(1));

    print_set(us2);

    std::unordered_multiset<A, decltype(lambda_hash)> ums;
    ums.emplace(A(1));
    ums.emplace(A(1));
    ums.emplace(A{3});

    print_set(ums);
     
    return 0;
}