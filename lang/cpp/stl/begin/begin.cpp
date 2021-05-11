#include <iostream>
#include <iterator>
#include <vector>

//std::iterator is obselete now.
//use begin(vector), end(vector) instead of v.begin, v.end
//this helps in writing template code

int main()
{
    std::vector<int> v {1, 2, 3, 4};
    auto itr = begin(v);
    //prints 1
    std::cout << *itr << std::endl;

    int a[] = {1, 2, -1, 2, 4};
    auto itr2 = std::begin(a);
    std::cout << *itr2 << std::endl;
    
    return 0;
}