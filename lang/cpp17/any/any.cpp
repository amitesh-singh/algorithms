#include <iostream>
#include <any>

int main()
{
    std::any data;
    data = 2;

    //to print it, we need to cast it.
    int x = std::any_cast<int> (data);
    std::cout << x << std::endl;

    data = std::string("ami");
    std::string s = std::any_cast<std::string>(data);
    std::cout << s2 << std::endl;

    data = "ami2";
    std::string &s2 = std::any_cast<std::string&>(data);

    std::cout << s2 << std::endl;

    return 0;
}