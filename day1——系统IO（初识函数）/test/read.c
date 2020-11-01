#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd0;
    char buf[100];
    ssize_t ret;
    fd0 = open("1.txt",O_RDONLY);

    if(fd0 == -1)
    {
        perror("open file");
        return -1;
    }

    ret = read(fd0, buf, sizeof(buf));

    printf("read :\t%ld\n",ret);
    printf("buf  :\t%s\n",buf);

    close(fd0);
    return 0;

}
