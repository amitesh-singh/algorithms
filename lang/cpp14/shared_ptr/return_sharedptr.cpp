#include <memory>
#include <iostream>

std::shared_ptr<int> returnX()
{
    return std::make_shared<int>(10);
}

int main()
{
    std::shared_ptr<int> s = returnX();
    std::cout << *s << std::endl;
    return 0;
}