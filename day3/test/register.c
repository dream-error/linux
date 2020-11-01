#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct userinfo{
	int num;			//用户序号
	char name[32];		//用户名
	char passwd[32];	//密码
}UserInfo;


/*实现注册功能*/
int main(int argc, char const *argv[])
{
	int i;

	//1,打开一个文件 userinfo.txt  如果不存在则创建
	int fd = open("userinfo.txt", O_RDWR | O_CREAT, 0666);
	if (-1 == fd)
	{
		perror("open failed");
		return -1;
	}

	//2,从键盘输入用户名+密码
	UserInfo  User1;	//定义一个结构体 User1

	for (i = 0; i < 3; ++i)		//连续注册3个用户信息
	{
		memset(&User1, 0, sizeof(User1));	//清空结构体

		User1.num = i;

		printf("输入用户名：");
		scanf("%s", User1.name);

		printf("输入密码：");
		scanf("%s", User1.passwd);

		//3,把用户信息结构体写入文件
		write(fd, &User1, sizeof(User1));
	}


	//4,关闭文件
	close(fd);

	return 0;
}








