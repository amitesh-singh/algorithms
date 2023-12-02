#include <iostream>
#include <utility>

class var {
    template <typename T>
    void insert(T val) {
        std::cout << "inserting: " << val << '\n';
    }

    template <typename T, typename... Args>
    void insert(T first, Args&&... rest) {
        insert(first);
        insert(std::forward<Args>(rest)...);
    }

public:
    template <typename... Args>
    var(Args&&... args) {
        insert(std::forward<Args>(args)...);
    }
};

int main() 
{
    var v(10, 20);
    return 0;
}
