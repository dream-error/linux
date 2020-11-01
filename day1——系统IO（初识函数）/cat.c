#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("请按照格式输入命令：%s <filename>\n", argv[0]);
        return -1;
    }

    int fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        perror("open file");
        return -1;
    }

    ssize_t ret;
    char buf[64];

    while(1)
    {
        memset(buf, 0, sizeof(buf));
        ret = read(fd, buf, sizeof(buf)-1);
        printf("%s",buf);
        if(ret == 0)
        {
            break;
        }

    }

    close(fd);

    return 0;
}