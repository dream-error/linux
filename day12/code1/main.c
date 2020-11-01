#include "list.h"

int main(int argc, char const *argv[])
{
	int i, num;
	//1,创建一个单向链表
	MyNode *list = List_Create();
    switch (switch_on)
    {
    default:
        break;
    }
	//2,键盘输入赋值3个到链表
    printf("臭傻逼")
	while(1)
    {
		scanf("%d", &num);
        
        if(num > 0)
        {
            List_Add_Node(list, num);
            List_Show_Data(list);

        }
        else if(num < 0)
        {
            List_Delete_repetition(list);
            List_Show_Data(list);
        //     num = -num;
        //     List_Remove_Node(list, num);
        //     List_Show_Data(list);
         }
        else 
        {
           break; 
        }

		
    }

    List_Remove_Node(list, num);
    List_Show_Data(list);
    List_Delete(list);

    return 0;
}


	



