#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedef一个结构体
{
	int Data;//应该改数据类型
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedef一个结构体指针
LNode* GetLastNode(LinkedList List)//返回尾节点的指针
{
	LNode* Last = NULL;
	LNode* Current;
	Current = List;
	while (Current != NULL)
	{
		Last = Current;
		Current = Current->Next;
	}
	return Last;
}
void ConnectLinkedList(LinkedList* PtrOfList1, LinkedList* PtrOfList2)
{
	if (PtrOfList1 == NULL || PtrOfList2 == NULL)
	{
		return;
	}
	if (*PtrOfList2 != NULL)
	{
		if (*PtrOfList1 == NULL)
		{
			*PtrOfList1 = *PtrOfList2;
		}
		else
		{
			GetLastNode(*PtrOfList1)->Next = *PtrOfList2;
		}
		*PtrOfList2 = NULL;
	}
}