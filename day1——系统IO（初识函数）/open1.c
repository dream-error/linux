#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    int fd ;

    while(1)
    {
    fd =open("1.txt", O_RDWR);
    
    if(-1 == fd)
    {
        perror("open failed");
        break;
    }
    printf("fd = %d\n",fd);
    }

    return 0;
}