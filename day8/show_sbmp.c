#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

/*********************************************************
**		@������ 	Show_Bmp
**		@��������	��LCD����ʾ400*200���ص��bmpͼƬ
**		@��������	pic_name����Ҫ��ʾ��ͼƬ��
**		@����ֵ		�ɹ�����0; ʧ�ܷ���-1
**		@˵��		��
*********************************************************/
int Show_S_Bmp(char *pic_name)
{
	//1,��LCD����test.bmp
	int lcd_fd = open("/dev/fb0", O_RDWR);
	if (-1 == lcd_fd)
	{
		perror("open lcd failed ");
		return -1;
	}
	//2,��ȡͼƬ���ص����ݣ����ҽ��н���
	int bmp_fd = open(pic_name, O_RDWR);
	if (-1 == bmp_fd)
	{
		perror("open bmp failed");
		return -1;
	}
	char buf[400*200*3];			//��Ŷ�ȡ��bmpͼƬ����
	lseek(bmp_fd, 54, SEEK_SET);	//����ǰ54�ֽ�
	read(bmp_fd, buf, sizeof(buf));	//��ȡ���ص���Ϣ
	unsigned int bmp_buf[400*200];	//800*480*4�ֽ�  ת��֮���ARGB����
	unsigned char A, R, G, B;	//���ͼƬ���ص��A R G B����
	int i, j;
	unsigned int tmp;
	for (i = 0; i < 400*200; ++i)
	{
		A = 0x00;	//͸����
		B = buf[3*i];		//��ɫ
		G = buf[3*i + 1];	//��ɫ
		R = buf[3*i + 2];	//��ɫ
		// A  R  G  B ==> ARGB   1234 = 1*1000 + 2*100 + 3*10 + 4
		// A << 24   R<< 16  G << 8  B
		bmp_buf[i] = A<<24 | R<<16 | G<<8 | B;
	}
	for (i = 0; i < 100; ++i)		//ʵ��400*200��BMPͼƬ���ص㵹ת
	{
		for (j = 0; j < 400; ++j)
		{
			//�ѵ�i�У���j�е����ص�� ��479-i�У���j�е����ص���н���
			tmp = bmp_buf[400*i+j];
			bmp_buf[400*i+j] = bmp_buf[400*(199-i)+j];
			bmp_buf[400*(199-i)+j] = tmp;	
		}	
	}
	
	//3,��LCDӳ�䵽�ڴ�ռ�
	unsigned int *lcdmap = mmap(NULL, 800*480*4, PROT_READ | PROT_WRITE,  MAP_SHARED, lcd_fd, 0);
	if(lcdmap == MAP_FAILED)
	{
		perror("mmap failed");
		return -1;
	}
	
	//4,�������ͼƬ����д�뵽LCD  bmp_buf[800*480] ==> lcdmap
/* 	for(i=0; i<800*480; i++)
	{
		lcdmap[i] = bmp_buf[i];
	} */
	for(i=0; i<200; i++)
	{
		for(j=0; j<400; j++)
		{
			//LCD�ϵ����ص�		ͼƬ�����ص�
			lcdmap[800*i+j] = bmp_buf[400*i+j];
		}
		//ÿ��ʾһ�����ݣ�����ʱ1ms
		usleep(3*1000);		//��ʱ3ms   
	}
	//��Ҷ����ʾͼƬ,����������ʾͼƬ
	
	//5,���LCDӳ��,�ر��ļ�
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

