//it uses fold expression instead

#include <iostream>
#include <utility>

class var {
    template <typename T>
    void insert(T val) {
        std::cout << "inserting: " << val << '\n';
    }

    template <typename... Args>
    void insert(Args&&... args) {
        (insert(std::forward<Args>(args)), ...);
    }

public:
    template <typename... Args>
    var(Args&&... args) {
        insert(std::forward<Args>(args)...);
    }
};

int main() {
    var v(10, 20, "hello");
    return 0;
}
