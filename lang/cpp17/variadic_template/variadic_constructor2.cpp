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

//using auto which is like replacement of templates
struct var2
{
    var2(auto&&... args)
    {
        parse_args(std::forward<decltype(args)>(args)...);
    }

    private:
        void parse(auto&& arg)
        {
            std::cout << arg << std::endl;
        }
        void parse_args(auto&&... args)
        {
            (parse(args), ...);
        }
};

int main()
{
    var v(10, 20, "hello");
    
    var2 v2(10, 20, "hey");
    
    return 0;
}
