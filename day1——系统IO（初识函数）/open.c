#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    int fd =open("1.txt", O_RDWR);
    if(-1 == fd)
    {
        perror("open failed");
        return -1;
    }
    printf("fd = %d\n",fd);

    return 0;
}