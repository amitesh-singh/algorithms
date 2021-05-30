#include <filesystem>
#include <iostream>


int main(int argc, char **argv)
{
   if (argc != 2)
     {
        std::cerr << argv[0] << " <remote path>\n";
        return 1;
     }
   std::filesystem::path mydir(argv[1]);

   if (std::filesystem::exists(mydir))
     {
        std::cout << mydir << "exists.\n";
     }
   std::cout << "root name: " <<  mydir.root_name() << std::endl;
   std::cout << "root path: " << mydir.root_path() << std::endl;
   std::cout << "relative path: " << mydir.relative_path() << std::endl;
   std::cout << "parent_path: " << mydir.parent_path() << std::endl;
   std::cout << "filename(): " << mydir.filename() << std::endl;
   std::cout << "stem(): " << mydir.stem() << std::endl;
   std::cout << "extension(): " << mydir.extension() << std::endl;

   return 0;
}
