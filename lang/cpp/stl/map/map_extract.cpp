#include <map>
#include <iostream>

class A
{
    public:
    int a;
    A(int x) : a(x)
    {
        std::cout << "A(int)\n";
    }

    bool operator<(const A& rhs) const
    {
        return a < rhs.a;
    }
};

int main()
{
    std::map<int, int> dict = { {1, 2}, {2, 3} };
    auto print_map = [](auto &m) {
        for (const auto& el: m) {
            std::cout << el.first << ": " << el.second << ", ";
        }
        std::cout << '\n';
    };

    // task is to change the existing key
    auto elem = dict.extract(1);
    elem.key() = 10;

    // the key is extracted, and it's not present in the map anymore.
    print_map(dict);

    dict.insert(std::move(elem));

    print_map(dict);

    std::map<A, int> dict2 {{A{1}, 1}, {A{2}, 2}};

    auto print_dict = [](auto& m) {
        for (const auto& e: m) {
            std::cout << e.first.a << " ";
        }

        std::cout << '\n';
    };

    print_dict(dict2);

    
    return 0;
}