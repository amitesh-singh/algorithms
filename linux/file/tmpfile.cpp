#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <linux/limits.h>
#include <iostream>


int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << argv[0] << " filename\n";
        exit(-1);
    }

    char tmpfilename[PATH_MAX];
    snprintf(tmpfilename, PATH_MAX - 1, "./%s.XXXXXX", argv[1]);
    std::cerr << "file: " << tmpfilename << std::endl;
    int fd = mkstemp(tmpfilename);
    if (fd == -1) {
        perror ("mkstemp:");
        std::cerr << "file: " << tmpfilename << std::endl;
        exit(-1);
    }
    FILE *outf = fdopen(fd, "w");

    if (fd == -1 || outf == NULL) {
        perror("fdopen");
        exit(-1);
    }
    return 0;
}