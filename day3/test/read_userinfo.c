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

int main(int argc, char const *argv[])		// ./read_userinfo  userinfo.txt
{
	UserInfo user1;
	size_t ret;

	//1,打开指定的文件 (打开存储用户信息的文件)	
	int fd = open(argv[1], O_RDWR);
	if (-1 == fd)
	{
		perror("open fialed");
		return -1;
	}
    ret = read(fd, &user1, sizeof(user1));
	//2,从文件中读取数据 ==> (读取的数据要跟写入的数据格式一致)
	while(ret > 0)
	{
		memset(&user1, 0, sizeof(user1));

		printf("num:%d, name:%s, passwd:%s\n", user1.num, user1.name, user1.passwd);
        ret = read(fd, &user1, sizeof(user1));
	}


	//3,关闭文件
	close(fd);

	return 0;
}

