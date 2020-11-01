#ifndef __LIST_H__
#define __LIST_H__


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}MyNode;		// MyNode == struct node


MyNode *List_Create();

void List_Show_Data(MyNode *list);
void List_Delete(MyNode *list);
void List_Delete_repetition(MyNode *list);

bool List_Add_Node(MyNode *list, int data);
bool List_Search_Node(MyNode *list, int data);
bool List_Remove_Node(MyNode *list, int data);

typedef struct node{
	int data;
	struct node *next;
}MyNode;		// MyNode == struct node


#endif