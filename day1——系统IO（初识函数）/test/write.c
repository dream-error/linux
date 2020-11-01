#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd0, fd1;
    char buf[100], buf1[100];
    char buf2[] = "你是不是傻";
    ssize_t ret, ret1;
    fd0 = open("1.txt",O_RDONLY);

    if(fd0 == -1)
    {
        perror("open file");
        return -1;
    }

    ret = read(fd0, buf, sizeof(buf));

    printf("读阶段\n");
    printf("read :\t%ld\n",ret);
    printf("buf  :\t%s\n",buf);
    printf("读阶段\n");
    
    close(fd0);

  //  fd1 = open("2.txt", O_RDWR | O_CREAT, 0777);
 fd1 = open("2.txt", O_RDWR|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    if(fd1 == -1)
    {
        perror("open file");
        return -1;
    }

    write(fd1, buf2, sizeof(buf2));

    ret1 = read(fd1, buf1, strlen(buf1));

    printf("写阶段\n");
    printf("read :\t%ld\n",ret1);
    printf("buf1 :\t%s\n",buf1);
    printf("写阶段\n");

    close(fd1);
    return 0;

}
 