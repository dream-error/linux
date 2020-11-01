#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>


int main(int argc, char const *argv[])
{

    int LCD_fd;
    unsigned int buf[800*480];
    int i;
    int red = 0x00ff0000;
    int white = 0x00ffffff;
    int bule = 0x000000ff;

    LCD_fd= open("/dev/fb0", O_RDWR);
    if(LCD_fd == -1)
    {
        perror("open file error");
        return -1;
    }


	
  
    for(i=0; i<800*160; i++)
	{	
		buf[i] = white;
    }
    for(i=160; i<800*320; i++)
	{	
		buf[i] = bule;
    }
    for(i=320; i<800*480; i++)
	{	
		buf[i] = red;
    }
    write (LCD_fd, buf, sizeof(buf));
    close(LCD_fd);
    
    return 0;

file_map_err:
	close(LCD_fd);
	return -1;
}