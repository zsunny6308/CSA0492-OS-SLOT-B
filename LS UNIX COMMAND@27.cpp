#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;

    mydir = opendir(argv[1]);
    while((myfile = readdir(mydir)) != NULL)
    {
        stat(myfile->d_name, &mystat);    
        printf("%d",mystat.st_size);
        printf(" %s\n", myfile->d_name);
    }
    closedir(mydir);
}