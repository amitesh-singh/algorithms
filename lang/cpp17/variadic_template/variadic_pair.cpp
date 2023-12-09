
#include <iostream>
#include <vector>

template<int N, typename T>
struct pair
{
private:
    void insert_pair(auto&& first, auto&& second)
    {
        data.push_back(first);
        data.push_back(second);
    }
    
    /*
    error: no matching function for call to 'pair<1, int>::insert()'
             insert(std::forward<decltype(rest)>(rest)...);
    */
    // the below line is needed or else we gonna get above errors.
    void insert() {}
    void insert(auto&& first, auto&& second, auto&&...rest)
    {
        insert_pair(std::forward<decltype(first)>(first),
                    std::forward<decltype(second)>(second));
        insert(std::forward<decltype(rest)>(rest)...);
    }
    
    pair(auto&&... args)
    {
        static_assert(sizeof...(args) == 2 * N, "invalid list of pairs");
        insert(std::forward<decltype(args)>(args)...);
    }
    
    void print()
    {
        for (auto&& d: data) {
            std::cout << d << ", ";
        }
    }

private:
    std::vector<T> data;
};

int main()
{
    pair<1, int> p{1, 2};
    
    p.print();

    return 0;
}