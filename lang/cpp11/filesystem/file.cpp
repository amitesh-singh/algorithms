#include <filesystem>
#include <fstream>
#include <iostream>

int main()
{
    std::filesystem::path p { "/tmp" };
    p /= "meh";

    std::cout << p << std::endl;

    // check if file exists
    if (std::filesystem::exists(p))
    {
        std::cout << "file exists\n";
    }
    else
        std::cout << "file does not exist\n";
    return 0;
}
