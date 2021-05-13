#include <tuple>
#include <iostream>

int main()
{
    std::tuple<int, std::string, int, float> t {1, "ami", 20, 20.2};
    int firstarg = std::get<0>(t)
    std::cout << firstarg << std::endl;
    
    return 0;
}