#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedef一个结构体
{
	int Data;//应该改数据类型
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedef一个结构体指针
LNode* InsertAt(LinkedList* PtrOfList, unsigned int Index, int Element)//将节点插入链表的Index位置//应当更改数据的类型
{
	LNode* Prev = NULL;
	LNode* New = NULL;
	LNode Temp;
	if (PtrOfList == NULL)
	{
		return NULL;
	}
	Temp.Next = *PtrOfList;
	Prev = (Index == 0) ? (&Temp) : GetNode(*PtrOfList, Index - 1);
	if (Prev != NULL) 
	{
		New = (LNode*)malloc(sizeof(LNode));
		New->Data = Element;
		New->Next = Prev->Next;
		Prev->Next = New;
	}
	*PtrOfList = Temp.Next;
	return New;
}
LNode* InsertAt(LinkedList* PtrOfList, unsigned int Index, int Element)//将节点插入链表的0号位置//应当更改数据的类型
{
	LNode* Prev = NULL;
	LNode* New = NULL;
	LNode Temp;
	if (PtrOfList == NULL)
	{
		return NULL;
	}
	Temp.Next = *PtrOfList;
	Prev = (Index == 0) ? (&Temp) : GetNode(*PtrOfList, Index - 1);
	if (Prev != NULL) 
	{
		New = (LNode*)malloc(sizeof(LNode));
		New->Data = Element;
		New->Next = Prev->Next;
		Prev->Next = New;
	}
	*PtrOfList = Temp.Next;
	return New;
}