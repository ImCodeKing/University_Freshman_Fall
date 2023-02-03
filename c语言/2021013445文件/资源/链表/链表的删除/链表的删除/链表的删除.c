#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedef一个结构体
{
	int Data;//应该改数据类型
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedef一个结构体指针
LNode* DeleteAt(LinkedList* PtrOfList, unsigned int Index)//删除尾结点
{
	LNode* Prev = NULL;
	LNode* ToDelete = NULL;
	LNode Temp;
	if (PtrOfList == NULL) 
	{
		return NULL;
	}
	Temp.Next = *PtrOfList;
	Prev = &Temp;
	Prev = (Index == 0) ? (&Temp) : GetNode(*PtrOfList, Index - 1);
	ToDelete = Prev->Next;
	if (Prev != NULL && ToDelete != NULL) 
	{
		Prev->Next = ToDelete->Next;
		free(ToDelete);
	}
	*PtrOfList = Temp.Next;
	return Prev->Next;
}
LNode* DeleteAt(LinkedList* PtrOfList, unsigned int Index)//删除头结点
{
	LNode* Prev = NULL;
	LNode* ToDelete = NULL;
	LNode Temp;
	if (PtrOfList == NULL) 
	{
		return NULL;
	}
	Temp.Next = *PtrOfList;
	Prev = &Temp;
	Prev = (Index == 0) ? (&Temp) : GetNode(*PtrOfList, Index - 1);
	ToDelete = Prev->Next;
	if (Prev != NULL && ToDelete != NULL)
	{
		Prev->Next = ToDelete->Next;
		free(ToDelete);
	}
	*PtrOfList = Temp.Next;
	return Prev->Next;
}
