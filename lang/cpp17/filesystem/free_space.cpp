#include <iostream>
#include <filesystem>

int main()
{
    std::filesystem::space_info tmp = std::filesystem::space("/tmp");
    //total size of the filesystem, in bytes
    std::cout << "capacity: " << tmp.capacity << "\n";
    //free space on the filesystem, in bytes
    std::cout << "free space: " << tmp.free << "\n";
    //free space available to a non-priviledged process 
    std::cout << "Available space: " << tmp.available << "\n";

    return 0;
}
