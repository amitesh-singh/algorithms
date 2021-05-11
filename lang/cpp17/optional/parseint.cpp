#include <iostream>
#include <optional>
#include <string>

std::optional<int> parseInt(const char *arg)
{
    try
    {
        return std::stoi(std::string(arg));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<" - couldn't parse " << arg << '\n';
    }
    
    return {}; // or std::nullopt
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << argv[0] << " arg1 arg2\n";
        return -1;
    }

    std::optional<int> arg1 = parseInt(argv[1]);
    auto arg2 = parseInt(argv[2]);
    
    if (arg1 && arg2)
    {
        std::cout << *arg1 << " " << *arg2 << std::endl;
    }

    return 0;
}