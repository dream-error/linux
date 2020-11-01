#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
    int fd0;

    fd0 = open("1.txt",O_RDONLY);

    if(fd0 == -1)
    {
        perror("open file");
        return -1;
    }

    close(fd0);
    return 0;

}
