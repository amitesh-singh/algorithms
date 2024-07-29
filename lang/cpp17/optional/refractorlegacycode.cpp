#include <optional>
#include <iostream>
//Refactoring legacy code with optional<T>
/*
In case you have lots of legacy code where default values like -1 or “” are used extensively, and you
 don’t want to change all of it at the same time, you can still replace the most critical parts of your 
 code with optionals, and leave the rest unchanged.

For this use the get_value_or (simply value_or for C++17’s std::optional) method to bridge up the two. 
It takes a value and returns it if the optional object turns out to be empty.
For instance, let’s consider the following legacy function:
*/
std::optional<int> newF(int x)
{
    if (x == -1)
        return {}; //std::nullopt;
    return x;
}
//return some int on success or -1 on failure
int oldF(int x)
{
    //return -1;
    return newF(x).value_or(-1);
}


int main()
{
    std::cout << oldF(-1) << std::endl;
    std::cout << oldF(2) << std::endl;
    return 0;
}