#include <iostream>
#include <string>

std::string reverseStr(std::string str)
{
    unsigned int start = 0, end = str.size() - 1;

    while (start < end)
    {
        std::swap(str[start++], str[end--]);
    }

    return str;
}

int main()
{
    std::cout << "reverse: CAT: " << reverseStr("CAT") << std::endl;
    
    return 0;
}
