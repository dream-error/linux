#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*在LCD上显示800*480像素点的bmp图片*/
int main(int argc, char const *argv[])
{
	//1,将图片的像素点信息读取出来
		//1)打开图片 --> test.bmp		open
		int bmp_fd = open("test.bmp", O_RDWR);
		if (-1 == bmp_fd)
		{
			perror("open bmp failed");
			return -1;
		}
		//2)读取图片像素点内容 -->跳过文件开头的54字节头信息 read
		char buf[800*480*3];			//存放读取的bmp图片内容
		lseek(bmp_fd, 54, SEEK_SET);	//跳过前54字节
		read(bmp_fd, buf, sizeof(buf));	//读取像素点信息

	//2,将读取的图片像素点数据写入到LCD
		//1)打开LCD文件  --> /dev/fb0	open
		int lcd_fd = open("/dev/fb0", O_RDWR);
		if (-1 == lcd_fd)
		{
			perror("open lcd failed ");
			return -1;
		}
		//2)把读取的像素点内容写入到LCD	write
		write(lcd_fd, buf, sizeof(buf));

	//3,关闭图片文件，关闭LCD文件	close
	close(bmp_fd);
	close(lcd_fd);

	return 0;
}









