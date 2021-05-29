#include <iostream>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
   if (argc != 2)
     {
        std::cerr << argv[0] << " <dir>\n";
        return 1;
     }
   DIR *dir;
   struct dirent *en;
   dir = opendir(argv[1]);
   if (dir)
     {
        while ((en = readdir(dir)))
               {
                std::cout << en->d_name << std::endl;
               }
     closedir(dir);
     }
   return 0;
}
