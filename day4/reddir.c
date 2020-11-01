#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("请按照格式输入：%s <dirname>\n", argv[0]);
		return -1;
	}

	//1,打开目录文件
	DIR *dp = opendir(argv[1]);
	if (NULL == dp)
	{
		perror("opendir failed");
		return -1;
	}

	struct dirent *fp;
	//2,读取目录中的内容
	while(1)
	{
		fp = readdir(dp);
		if (fp == NULL)
		{
			break;	//读取完毕，结束循环
		}
		if(strcmp(fp->d_name,".")!=0 && strcmp(fp->d_name,"..")!=0)
		{	
			if(strcmp(fp->d_name +(strlen(fp->d_name)-4),".bmp")==0)
				printf("%s\n",fp->d_name);
		}

	}

	//3,关闭目录文件
	closedir(dp);

	return 0;
}








