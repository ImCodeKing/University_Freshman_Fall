#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedef一个结构体
{
	int Data;//应该改数据类型
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedef一个结构体指针
void InputElement(int* PtrOfElement) //链表输入数字（初始化）
{
	if (PtrOfElement == NULL)
	{
		return;
	}
	memset(PtrOfElement, 0, sizeof(int));
	scanf("%d", PtrOfElement);//应该%d类型
}
LinkedList CreateLinkedListR(int Count)//创建链表//尾插法//应该改数据类型
{
	LinkedList Res;
	LNode* Head;
	LNode* New;
	LNode* End;
	Head = (LNode*)malloc(sizeof(LNode));
	Head->Next = NULL;
	End = Head;
	while (Count-- > 0)
	{
		New = (LNode*)malloc(sizeof(LNode));
		InputElement(&New->Data);
		New->Next = End->Next;
		End->Next = New;
		End = New;
	}
	Res = Head->Next;
	free(Head);
	return Res;
}
LinkedList CreateLinkedListF(int Count)//头插法
{
	LinkedList Res;
	LNode* Head;
	LNode* New;
	LNode* End;
	Head = (LNode*)malloc(sizeof(LNode));
	Head->Next = NULL;
	End = Head;
	while (Count-- > 0) 
	{
		New = (LNode*)malloc(sizeof(LNode));
		InputElement(&New->Data);
		New->Next = Head->Next;
		Head->Next = New;
		End = New;
	}
	Res = Head->Next;
	free(Head);
	return Res;
}