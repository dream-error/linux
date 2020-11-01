int main(int argc, char const *argv[])
{
	int i, num;
	//1,创建一个单向链表
	MyNode *list = List_Create();

	//2,键盘输入赋值3个到链表
	
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
            num = -num;
            List_Remove_Node(list, num);
            List_Show_Data(list);
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


	