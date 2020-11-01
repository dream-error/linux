#include <stdio.h>
int main(void)
{
    int bmp_fd;
    int fd;

    bmp_fd = open("test.bmp", O_RDWR);
    if(bmp_fd == -1)
    {
        perror("open file error");
        return -1;
    }
    char buf[800*480*3];
    lseek(bmp_fd, 54, SEEK_SET);
    read(bmp_fd, buf, sizeof(buf));

    int lcd_fd;

    fp = open("/dev/fb0", O_RDWR);   
    if(lcd_fd == -1)
    {
        perror("open file error");
        return -1;
    } 

    write(lcd_fd, buf, sizeof(buf));

    close(bmp_fd);
    close(lcd_fd);


    return 0;
}
