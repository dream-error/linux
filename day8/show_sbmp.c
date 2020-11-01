#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

/*********************************************************
**		@函数名 	Show_Bmp
**		@函数功能	在LCD上显示400*200像素点的bmp图片
**		@函数参数	pic_name：需要显示的图片名
**		@返回值		成功返回0; 失败返回-1
**		@说明		无
*********************************************************/
int Show_S_Bmp(char *pic_name)
{
	//1,打开LCD，打开test.bmp
	int lcd_fd = open("/dev/fb0", O_RDWR);
	if (-1 == lcd_fd)
	{
		perror("open lcd failed ");
		return -1;
	}
	//2,读取图片像素点数据，并且进行解码
	int bmp_fd = open(pic_name, O_RDWR);
	if (-1 == bmp_fd)
	{
		perror("open bmp failed");
		return -1;
	}
	char buf[400*200*3];			//存放读取的bmp图片内容
	lseek(bmp_fd, 54, SEEK_SET);	//跳过前54字节
	read(bmp_fd, buf, sizeof(buf));	//读取像素点信息
	unsigned int bmp_buf[400*200];	//800*480*4字节  转换之后的ARGB数据
	unsigned char A, R, G, B;	//存放图片像素点的A R G B数据
	int i, j;
	unsigned int tmp;
	for (i = 0; i < 400*200; ++i)
	{
		A = 0x00;	//透明度
		B = buf[3*i];		//蓝色
		G = buf[3*i + 1];	//绿色
		R = buf[3*i + 2];	//红色
		// A  R  G  B ==> ARGB   1234 = 1*1000 + 2*100 + 3*10 + 4
		// A << 24   R<< 16  G << 8  B
		bmp_buf[i] = A<<24 | R<<16 | G<<8 | B;
	}
	for (i = 0; i < 100; ++i)		//实现400*200的BMP图片像素点倒转
	{
		for (j = 0; j < 400; ++j)
		{
			//把第i行，第j列的像素点跟 第479-i行，第j列的像素点进行交换
			tmp = bmp_buf[400*i+j];
			bmp_buf[400*i+j] = bmp_buf[400*(199-i)+j];
			bmp_buf[400*(199-i)+j] = tmp;	
		}	
	}
	
	//3,将LCD映射到内存空间
	unsigned int *lcdmap = mmap(NULL, 800*480*4, PROT_READ | PROT_WRITE,  MAP_SHARED, lcd_fd, 0);
	if(lcdmap == MAP_FAILED)
	{
		perror("mmap failed");
		return -1;
	}
	
	//4,将解码的图片数据写入到LCD  bmp_buf[800*480] ==> lcdmap
/* 	for(i=0; i<800*480; i++)
	{
		lcdmap[i] = bmp_buf[i];
	} */
	for(i=0; i<200; i++)
	{
		for(j=0; j<400; j++)
		{
			//LCD上的像素点		图片的像素点
			lcdmap[800*i+j] = bmp_buf[400*i+j];
		}
		//每显示一行数据，就延时1ms
		usleep(3*1000);		//延时3ms   
	}
	//百叶窗显示图片,从左往右显示图片
	
	//5,解除LCD映射,关闭文件
	munmap(lcdmap, 800*480*4);
	close(lcd_fd);
	close(bmp_fd);
	return 0;
}

int main()
{
	Show_S_Bmp("small.bmp");
	
	return 0;
}


