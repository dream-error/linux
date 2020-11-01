#include <stdio.h>

int main()
{
    FILE *fp = fopen("hello.txt", "w+");

    if(NULL == fp)
    {
        perror("fopen failed：");
        return -1;
    }

    printf("fopen success!\n");

    fclose(fp);
    return 0;

}