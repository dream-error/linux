#include <stdio.h>

int main()
{

    FILE fp = fopen("46.txt","rw+")

    char buf[46]="dasf afadfdfasfgdgfdasf";

    ret = fwrite(buf, 10, 5, fp);

    ret2 = fread(buf1, 10, 5, fp);
     

}