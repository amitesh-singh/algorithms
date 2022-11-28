#include <iostream>
#include <filesystem>

int main()
{
    size_t s = std::filesystem::file_size("./simple.cpp");
    std::cout << s << std::endl;

    return 0;
}
