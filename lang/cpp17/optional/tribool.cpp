#include <iostream>
#include <optional>

int main()
{
    std::optional<bool> tribool1;
   // *tribool1 = true;
    tribool1.emplace(true);
    
    std::cout << tribool1.value() << std::endl;

    return 0;
}