#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    char buf[64];

    fd = open("read.c", O_RDONLY);

    if(fd == -1)
    {
        perror("open file failed");
        return -1;
    }

    ssize_t ret = read(fd, buf, sizeof(buf)-1);

    printf("read bytes : %ld\n", ret);
    printf("%s", buf);

    close(fd);

    return 0;
}