#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 0. 设计链表节点结构体
typedef struct node{
	int data;
	struct node *next;
}MyNode;		// MyNode == struct node

// 1. 创建链表 (创建链表头结点)
MyNode *List_Create()
{
	//1,申请结点的堆空间
	MyNode *list = (MyNode *)malloc(sizeof(MyNode));
	if (NULL == list)
	{
		perror("malloc head failed");
		return NULL;
	}
	//2,对节点进行赋值
	list->next = NULL;
	//3,返回节点指针
	return list;
}

// 2. 添加链表节点
bool List_Add_Node(MyNode *list, int data)
{
	//1)申请结点空间
	MyNode *NewNode = (MyNode *)malloc(sizeof(MyNode));
	if (NULL == NewNode)
	{
		perror("malloc NewNode failed");
		return false;
	}	
	//2)对节点进行赋值
	NewNode->data = data;
	NewNode->next = NULL;

	//3)把新的节点加入到链表 （头插法）
	// NewNode->next = list->next;
	// list->next = NewNode;
	
	//尾插法 (先找到最后一个节点)
	MyNode *p = list;
	while(p->next != NULL)	//循环执行完毕，P就是最后一个节点
	{
		p = p->next;
	}
	p->next = NewNode;
	return true;

	//尾插法如何实现？
}

// 3. 显示链表
void List_Show_Data(MyNode *list)
{
	MyNode *p = list->next;		//p指向头结点的下一个
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;	//p指针不断的往后偏移
	}
	printf("\n");
}

// 4. 查找链表节点
bool List_Search_Node(MyNode *list, int data)
{
	//对链表进行遍历
	MyNode *p = list->next;
	while(p != NULL)
	{
		if (p->data == data)
		{
			printf("找到了节点！\n");
			return true;
		}

		p = p->next;
	}
	printf("没有这个节点！\n");
	return false;
}

// 5. 删除链表节点
bool List_Remove_Node(MyNode *list, int data)
{
	//1) 找到需要被删除的节点
	MyNode *p = list->next;
	MyNode *q = list;		//q指针指向p节点的前一个节点
	while(p != NULL)
	{
		if (p->data == data)	//找到了需要被删除的节点
		{
			q->next = p->next;
			free(p);
			//只删除一个节点
			// printf("删除节点成功！\n");
			// return true;	
			//如果需要删除重复的节点	
			p = q->next;
			continue;
		}
		q = p;
		p = p->next;	//q指针指向p节点的前一个节点
	}

	//printf("没有这个节点！\n");
	return false;
	//2) 从链表中删除这个节点

}



// 6. 删除链表  --> 把链表中的每个节点都释放掉
void List_Delete(MyNode *list)
{
	int i = 0;
	MyNode *p, *q;
	q = list;
	p = list->next;
	while(p != NULL)
	{
		free(q);
		q = p;
		p = p->next;
		i++;
	}
	free(q);	//释放最后一个节点
	printf("一共释放了%d个数据节点\n", i);
}


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












